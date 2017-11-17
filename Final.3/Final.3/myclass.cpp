#include "myclass.h"
#include <QDebug>

MyClass::MyClass(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

	indexThread = new IndexThread;
	workThread = new WorkThread(this);

	isIn = false;
	needIn = false;
	connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));
	connect(indexThread, SIGNAL(finshGet()), this, SIGNAL(getAppSignal()));
	connect(workThread, SIGNAL(searchFinsh()), this, SIGNAL(showResultSignal()));
	connect(this, SIGNAL(showResultSignal()), this, SLOT(showResult()));
	connect(this, SIGNAL(getAppSignal()), this, SLOT(getApp()));
	QFile file("index.ini");
	file.open(QIODevice::ReadOnly);
	if (file.size() == 0){
		needIn = true;
		QMessageBox::information(this, tr("注意"),
			tr("当前没有索引文件\n请自行建立."));
	}
	if (!needIn){
		getIndex();
	}

	creatMenu();
	creadTableWidget();
}

void MyClass::paintEvent(QPaintEvent *event)
{
	int w = tableWidget->width();
	tableWidget->setColumnWidth(0, 0.2*w);
	tableWidget->setColumnWidth(1, 0.7*w);
	tableWidget->setColumnWidth(2, 0.1*w);
}

void MyClass::customMenuRequested(QPoint pos)
{
	QTableWidgetItem* item = tableWidget->itemAt(pos);
	QMenu *tableMenu = new QMenu(tableWidget);
	QAction *open = new QAction(tr("打开(&O)"), tableMenu);
	QAction *folder = new QAction(tr("打开路径(&F)"), tableMenu);
	QAction *copy = new QAction(tr("复制文件路径(&C)"), tableMenu);
	connect(open, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(folder, SIGNAL(triggered()), this, SLOT(openPath()));
	connect(copy, SIGNAL(triggered()), this, SLOT(Copy()));
	tableMenu->addAction(open);
	tableMenu->addAction(folder);
	tableMenu->addAction(copy);
	tableMenu->exec(QCursor::pos());
}

void MyClass::openFile()
{
	QTableWidgetItem* item = tableWidget->currentItem();
	int row = item->row();
	item = tableWidget->item(row, 1);
	QString str = item->text();
	str.replace("/", "\\");
	QProcess::startDetached("explorer " + str);
}

void MyClass::openPath()
{
	QTableWidgetItem* item = tableWidget->currentItem();
	int row = item->row();
	item = tableWidget->item(row, 1);
	QString str = item->text();
	QFileInfo info(str);
	str = info.path();
	str.replace("/", "\\");
	QProcess::startDetached("explorer " + str);
}

void MyClass::Copy()
{
	QTableWidgetItem* item = tableWidget->currentItem();
	int row = item->row();
	item = tableWidget->item(row, 1);
	QString str = item->text();
	QClipboard *board = QApplication::clipboard();
	board->setText(str);
}

void MyClass::creadTableWidget()
{
	tableWidget->setColumnCount(3);
	QStringList header;
	header << "文件名" << "路径" << "大小";
	tableWidget->setHorizontalHeaderLabels(header);
	tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(tableWidget, SIGNAL(customContextMenuRequested(QPoint)), SLOT(customMenuRequested(QPoint)));

	tableWidget->setFrameShape(QFrame::NoFrame);
	tableWidget->setShowGrid(false);
	tableWidget->verticalHeader()->setVisible(false);
}

void MyClass::creatMenu()
{
	QMenuBar *menuBar = new QMenuBar(this);
	QMenu *newMenu = new QMenu(tr("文件"), menuBar);
	QMenu *helpMenu = new QMenu(tr("帮助"), menuBar);
	QAction *newAction = new QAction(tr("新建索引"), newMenu);
	QAction *helpAction = new QAction(tr("帮助"), helpMenu);
	QAction *aboutAction = new QAction(tr("关于"), helpMenu);
	connect(newAction, SIGNAL(triggered()), this, SLOT(creatIndex()));
	connect(helpAction, SIGNAL(triggered()), this, SLOT(help()));
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
	newMenu->addAction(newAction);
	helpMenu->addAction(helpAction);
	helpMenu->addAction(aboutAction);
	menuBar->addMenu(newMenu);
	menuBar->addMenu(helpMenu);
	setMenuBar(menuBar);
}

void MyClass::about()
{
	QMessageBox::information(this, tr("关于"),
		tr("A-Everything 1.0\n      by Aesma"));
}

void MyClass::help()
{
	QMessageBox::information(this, tr("帮助"),
		tr("第一次打开建立索引\n之后可手动建立\n建立索引是用的是当前线程\n所以会卡住蛮长时间的= =\n我实在懒得改了\n搜索跟通过配置文件索引都是用的其他线程\n卡住的时候别乱动\n不然会更久"));
}

void MyClass::creatIndex()
{
	app.creatIndex();
	isIn = true;
	QMessageBox::information(this, tr("完成"),
		tr("索引建立完毕."));
}

void MyClass::getIndex()
{
	indexThread->start();
	isIn = true;
}

void MyClass::getApp()
{
	app = indexThread->getApp();
	QMessageBox::information(this, tr("信息"),
		tr("已自动建立索引."));
}

void MyClass::search()
{
	if (!isIn){
		QMessageBox::critical(this, tr("错误"),
			tr("没有索引."));
		return;
	}
	QString str = lineEdit->text();
	workThread->setWork(str, app);
	workThread->start();
}

void MyClass::showResult()
{
	QVector<fileNode>result = workThread->getResult();
	int h = result.size();
	tableWidget->setRowCount(h);
	if (h == 0){
		QMessageBox::information(this, tr(""),
			tr("没有找到该文件."));
		return;
	}
	for (int i = 0; i < h; i++)
	{
		tableWidget->setItem(i, 0, new QTableWidgetItem(result[i].fileName));
		tableWidget->setItem(i, 1, new QTableWidgetItem(result[i].filePath));
		QString temp = QString::number(result[i].fileSize) + " Byte";
		tableWidget->setItem(i, 2, new QTableWidgetItem(temp));
	}
}

MyClass::~MyClass()
{

}
