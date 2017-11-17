#include "myclass.h"

MyClass::MyClass(QWidget *parent)
: QMainWindow(parent)
{
	setupUi(this);

	mark = 0;
	scene = new QGraphicsScene(0, 0, groupBox_3->width(), groupBox_3->height());
	mapView = new MyView(groupBox_3);
	mapView->setScene(scene);
	mapView->move(0, 20);
	mapItem = new MyItem;
	scene->addItem(mapItem);
	needIn = false;
	QFile file1("./data/vertices.dat");
	file1.open(QIODevice::ReadOnly);
	QFile file2("./data/edge.dat");
	file2.open(QIODevice::ReadOnly);
	if (file1.size() == 0 || file2.size() == 0){
		QMessageBox::information(this, tr("注意"),
			tr("目前没有地图数据\n请手动导入."));
		needIn = true;
	}
	if (!needIn){
		getMap();
	}

	dealCtr();
}

void MyClass::paintEvent(QPaintEvent *event)
{
	mapView->setGeometry(0, 0, groupBox_3->width(), height() - 75);
}

void MyClass::dealCtr()
{
	connect(inButton, SIGNAL(clicked()), this, SLOT(setMap()));
	connect(addEdgeButton, SIGNAL(clicked()), this, SLOT(addEdge()));
	connect(delEdgeButton, SIGNAL(clicked()), this, SLOT(delEdge()));
	connect(addVerButton, SIGNAL(clicked()), this, SLOT(addVertice()));
	connect(delVerButton, SIGNAL(clicked()), this, SLOT(delVertice()));
	connect(seaEdgeButton, SIGNAL(clicked()), this, SLOT(seaEdge()));
	connect(seaVerButton, SIGNAL(clicked()), this, SLOT(seaVertice()));
	connect(minLength, SIGNAL(clicked()), this, SLOT(minLengthSingal()));
	connect(minChange, SIGNAL(clicked()), this, SLOT(minChangeSignal()));
	connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));
	connect(outButton, SIGNAL(clicked()), this, SLOT(outData()));
}

void MyClass::getMap()
{
	sub = new Subway;
	QMessageBox::information(this, tr("注意"),
		tr("已导入数据\n无需手动导入."));
}

void MyClass::setMap()
{
	QMessageBox::information(this, tr("注意事项"),
		tr("只能读取Excel文件\n而且内容的格式一定要和我放在文件夹里的那个一样才行\n不然会直接GG掉\n还有就是读取Excel速度会比较慢 耐心等一会."));
	filePath = QFileDialog::getOpenFileName(
		this,
		"Open Document",
		QDir::currentPath(),
		"Excel(*.xlsx;*.xls)");
	if (filePath == ""){
		QMessageBox::warning(this, tr("Error"),
			tr("没有选择文件!"));
		return;
	}
	sub = new Subway(filePath);
	QMessageBox::information(this, tr("Success"),
		tr("导入数据成功."));
}

void MyClass::addEdge()
{
	QString edge = addEdgeEdit->text();
	QStringList list = edge.split("——");
	int cost = list[2].toInt();
	sub->addEdge(list[0], list[1], cost);
}

void MyClass::delEdge()
{
	QString edge = delEdgeEdit->text();
	QStringList list = edge.split("——");
	sub->delEdge(list[0], list[1]);
}

void MyClass::addVertice()
{
	QString ver = addVerEdit->text();
	sub->addVertice(ver);
}

void MyClass::delVertice()
{
	QString ver = delVerEdit->text();
	sub->delVertice(ver);
}

void MyClass::seaEdge()
{
	QString str = seaEdgeEdit->text();
	QStringList list = sub->searchEdge(str);
	edgeWidget->setWindowTitle(str);
	edgeWidget->setColumnCount(1);
	edgeWidget->setRowCount(list.size());
	QStringList header;
	header << "站点";
	edgeWidget->setHorizontalHeaderLabels(header);
	for (int i = 0; i < list.size(); i++)
		edgeWidget->setItem(i, 0, new QTableWidgetItem(list[i]));
}

void MyClass::seaVertice()
{
	QString str = seaVerEdit->text();
	QStringList list = sub->searchVertice(str);
	if (list.size() == 0)
		return;
	verWidget->setWindowTitle(str);
	verWidget->setColumnCount(1);
	verWidget->setRowCount(list.size());
	QStringList header;
	header << "线路";
	verWidget->setHorizontalHeaderLabels(header);
	for (int i = 0; i < list.size();i++)
		verWidget->setItem(i, 0, new QTableWidgetItem(list[i]));
}

void MyClass::outData()
{
	QMessageBox::information(this, tr("信息"),
		tr("数据就在data文件夹里了."));
}

void MyClass::minLengthSingal()
{
	mark = 1;
}

void MyClass::minChangeSignal()
{
	mark = 2;
}

void MyClass::search()
{
	if (mark == 1){
		QString beq = beqEdit->text();
		QString end = endEdit->text();
		if (beq == ""){
			QMessageBox::critical(this, tr("Error"),
				tr("没有输入起始站."));
			return;
		}
		if (end == ""){
			QMessageBox::critical(this, tr("Error"),
				tr("没有输入终点站."));
			return;
		}
		QList<Node>nodeList = sub->getMinLenPlan(beq, end);
		int size = nodeList.size();
		getWidget->setRowCount(size);
		getWidget->setColumnCount(3);
		QStringList header;
		header << "站点" << "路线" << "距离";
		getWidget->setHorizontalHeaderLabels(header);
		int j = 0;
		for (int i = size - 1; i >= 0; i--)
		{
			if (i != size - 1){
				QString num = QString::number(nodeList[i].len) + "米";
				getWidget->setItem(j, 2, new QTableWidgetItem(num));
			}
			else
				getWidget->setItem(j, 2, new QTableWidgetItem(""));
			getWidget->setItem(j, 0, new QTableWidgetItem(nodeList[i].stop));
			getWidget->setItem(j, 1, new QTableWidgetItem(nodeList[i].path));
			j++;
		}
	}
	else if (mark == 2){
		QMessageBox::information(this, tr("啊···"),
			tr("这个没做这个没做·恩··没做."));
	}
	else
		QMessageBox::warning(this, tr("Error"),
		tr("没选乘车方案."));
}

MyClass::~MyClass()
{

}
