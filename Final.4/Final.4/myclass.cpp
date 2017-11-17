#include "myclass.h"

MyClass::MyClass(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

	direct = 0;
	menuBarSize = 20;
	isRun = false;
	isIn = false;
	mapH = 0;
	mapW = 0;
	wall = new QPixmap("./img/wall.png");
	manPix = new QPixmap("./img/man.png");
	goal = new QPixmap("./img/goal.png");
	ground = new QPixmap("./img/ground.png");
	boxPix = new QPixmap("./img/box.png");
	wall->scaledToWidth(30);
	wall->scaledToHeight(30);
	manPix->scaledToWidth(30);
	manPix->scaledToHeight(30);
	goal->scaledToWidth(30);
	goal->scaledToHeight(30);
	ground->scaledToWidth(30);
	ground->scaledToHeight(30);
	boxPix->scaledToWidth(30);
	boxPix->scaledToHeight(30);
	QMediaPlaylist *L1 = new QMediaPlaylist;
	QMediaPlaylist *L2 = new QMediaPlaylist;
	L1->addMedia(QUrl::fromLocalFile(".\\sound\\begin.mp3"));
	L2->addMedia(QUrl::fromLocalFile(".\\sound\\run.mp3"));
	L1->setCurrentIndex(1);
	L1->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
	L2->setCurrentIndex(1);
	L2->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
	beginSound = new QMediaPlayer;
	runSound = new QMediaPlayer;
	loseSound = new QMediaPlayer;
	winSound = new QMediaPlayer;
	beginSound->setPlaylist(L1);
	runSound->setPlaylist(L2);
	loseSound->setMedia(QUrl::fromLocalFile(".\\sound\\lose.mp3"));
	winSound->setMedia(QUrl::fromLocalFile(".\\sound\\win.mp3"));

	beginSound->play();

	creatMenu();
}

void MyClass::autoSlot()
{
	update();
}

void MyClass::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Up:
		direct = 1;
		break;
	case Qt::Key_Right:
		direct = 2;
		break;
	case Qt::Key_Down:
		direct = 3;
		break;
	case Qt::Key_Left:
		direct = 4;
		break;
	default:
		break;
	}
	if (isIn){
		pushBox->changeDirect(direct);
		man = pushBox->getMan();
		box = pushBox->getBox();
		if (pushBox->getResult()){
			runSound->stop();
			winSound->play();
			isIn = false;
			isRun = false;
			beginSound->play();
			QMessageBox::information(this, tr(""),
				tr("YOU WIN!"));
			delete pushBox;
			mapH = 0;
			mapW = 0;
		}
		else{
			int x = box.x;
			int y = box.y;
			if (box.x != 0 && box.y != 0 && box.x != mapW - 1 && box.y != mapH - 1){
				if (!isRood[x + 1][y] && !isRood[x][y + 1]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					beginSound->play();
					QMessageBox::information(this, tr(""),
						tr("YOU LOSE!"));
					delete pushBox;
					mapH = 0;
					mapW = 0;
				}
				else if (!isRood[x][y + 1] && !isRood[x - 1][y]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					beginSound->play();
					QMessageBox::information(this, tr(""),
						tr("YOU LOSE!"));
					delete pushBox;
					mapH = 0;
					mapW = 0;
				}
				else if (!isRood[x - 1][y] && !isRood[x][y - 1]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					beginSound->play();
					QMessageBox::information(this, tr(""),
						tr("YOU LOSE!"));
					delete pushBox;
					mapH = 0;
					mapW = 0;
				}
				else if (!isRood[x][y - 1] && !isRood[x + 1][y]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					beginSound->play();
					QMessageBox::information(this, tr(""),
						tr("YOU LOSE!"));
					delete pushBox;
					mapH = 0;
					mapW = 0;
				}
			}
			else if (x == 0 || x == mapW - 1){
				if (y == 0 || y == mapH - 1){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					beginSound->play();
					QMessageBox::information(this, tr(""),
						tr("YOU LOSE!"));
					delete pushBox;
					mapH = 0;
					mapW = 0;
				}
				else if (!isRood[x][y - 1] && !isRood[x][y + 1]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					beginSound->play();
					QMessageBox::information(this, tr(""),
						tr("YOU LOSE!"));
					delete pushBox;
					mapH = 0;
					mapW = 0;
				}
			}
			else if (y == 0 || y == mapH - 1){
				if (x == 0 || x == mapW - 1){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					beginSound->play();
					QMessageBox::information(this, tr(""),
						tr("YOU LOSE!"));
					delete pushBox;
					mapH = 0;
					mapW = 0;
				}
				else if (!isRood[x + 1][y] && !isRood[x - 1][y]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					beginSound->play();
					QMessageBox::information(this, tr(""),
						tr("YOU LOSE!"));		
					delete pushBox;
					mapH = 0;
					mapW = 0;
				}
			}
		}
	}
	update();
	QWidget::keyPressEvent(event);
}

void MyClass::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QPixmap startMap("./img/start.png");
	QRect startRect = startMap.rect();
	if (!isRun){
		setFixedSize(startRect.width(), startRect.height());
		painter.translate(0, menuBarSize);
		painter.drawPixmap(startRect, startMap);
		return;
	}
	painter.translate(0, menuBarSize);
	int w = mapW * 30;
	int h = mapH * 30 + menuBarSize;
	setFixedSize(w, h);
	for (int i = 0; i < mapW; i++)
	for (int j = 0; j < mapH; j++)
	{
		if (!isRood[i][j])
			painter.drawPixmap(i * 30, j * 30, *wall);
		else if (man.x == i&&man.y == j)
			painter.drawPixmap(i * 30, j * 30, *manPix);
		else if (end.x == i&&end.y == j)
			painter.drawPixmap(i * 30, j * 30, *goal);
		else if (box.x == i&&box.y == j)
			painter.drawPixmap(i * 30, j * 30, *boxPix);
		else
			painter.drawPixmap(i * 30, j * 30, *ground);
	}
}

void MyClass::autoGame()
{
	if (!isIn){
		QMessageBox::critical(this, tr("ע��"),
			tr("û�е����ͼ\n���ȵ����ͼ."));
		return;
	}
	if (!isRun){
		QMessageBox::critical(this, tr("ע��"),
			tr("û�п�ʼ��Ϸ\n�޷��Զ�Ѱ·."));
		return;
	}
	while (1){
		bool temp = pushBox->Auto();
		man = pushBox->getMan();
		box = pushBox->getBox();
		if (!temp){
			QMessageBox::information(this, tr("LOSE"),
				tr("�޽�ĵ�ͼ!"));
			isRun = false;
			isIn = false;
			runSound->stop();
			loseSound->play();
			beginSound->play();
			delete pushBox;
			mapH = 0;
			mapW = 0;
			update();
			break;
		}
		if (pushBox->getResult()){
			runSound->stop();
			winSound->play();
			isIn = false;
			isRun = false;
			beginSound->play();
			QMessageBox::information(this, tr(""),
				tr("YOU WIN!"));
			delete pushBox;
			mapH = 0;
			mapW = 0;
			update();
			break;
		}
		else{
			int x = box.x;
			int y = box.y;
			if (box.x != 0 && box.y != 0 && box.x != mapW - 1 && box.y != mapH - 1){
				if (!isRood[x + 1][y] && !isRood[x][y + 1]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					QMessageBox::information(this, tr(""),
						tr("�޽�ĵ�ͼ!"));
					beginSound->play();
					delete pushBox;
					mapH = 0;
					mapW = 0;
					break;
				}
				else if (!isRood[x][y + 1] && !isRood[x - 1][y]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					QMessageBox::information(this, tr(""),
						tr("�޽�ĵ�ͼ!"));
					beginSound->play();
					delete pushBox;
					mapH = 0;
					mapW = 0;
					break;
				}
				else if (!isRood[x - 1][y] && !isRood[x][y - 1]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					QMessageBox::information(this, tr(""),
						tr("�޽�ĵ�ͼ!"));
					beginSound->play();
					delete pushBox;
					mapH = 0;
					mapW = 0;
					break;
				}
				else if (!isRood[x][y - 1] && !isRood[x + 1][y]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					QMessageBox::information(this, tr(""),
						tr("�޽�ĵ�ͼ!"));
					beginSound->play();
					delete pushBox;
					mapH = 0;
					mapW = 0;
					break;
				}
			}
			else if (x == 0 || x == mapW - 1){
				if (y == 0 || y == mapH - 1){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					QMessageBox::information(this, tr(""),
						tr("�޽�ĵ�ͼ!"));
					beginSound->play();
					delete pushBox;
					mapH = 0;
					mapW = 0;
					break;
				}
				else if (!isRood[x][y - 1] && !isRood[x][y + 1]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					QMessageBox::information(this, tr(""),
						tr("�޽�ĵ�ͼ!"));
					beginSound->play();
					delete pushBox;
					mapH = 0;
					mapW = 0;
					break;
				}
			}
			else if (y == 0 || y == mapH - 1){
				if (x == 0 || x == mapW - 1){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					QMessageBox::information(this, tr(""),
						tr("�޽�ĵ�ͼ!"));
					beginSound->play();
					delete pushBox;
					mapH = 0;
					mapW = 0;
					break;
				}
				else if (!isRood[x + 1][y] && !isRood[x - 1][y]){
					isIn = false;
					isRun = false;
					runSound->stop();
					loseSound->play();
					QMessageBox::information(this, tr(""),
						tr("�޽�ĵ�ͼ!"));
					delete pushBox;
					mapH = 0;
					mapW = 0;
					beginSound->play();
					break;
				}
			}
		}
		repaint();
		Sleep(200);
	}
}

void MyClass::quitGame()
{
	if (!isRun){
		QMessageBox::critical(this, tr("����"),
			tr("û�п�ʼ��Ϸ\n�޷��˳�."));
		return;
	}
	isRun = false;
	isIn = false;
	mapW = 0;
	mapH = 0;
	delete pushBox;
	runSound->stop();
	beginSound->play();
}

void MyClass::creatMenu()
{
	QMenuBar *menuBar = new QMenuBar(this);
	QMenu *gameMenu = new QMenu(tr("��Ϸ"), menuBar);
	QMenu *helpMenu = new QMenu(tr("����"), menuBar);
	QAction *startGame = new QAction(tr("��ʼ��Ϸ"), gameMenu);
	QAction *inMap = new QAction(tr("�����ͼ"), gameMenu);
	QAction *autoGame = new QAction(tr("�Զ����"), gameMenu);
	QAction *quitGame = new QAction(tr("�˳���Ϸ"), gameMenu);
	QAction *help = new QAction(tr("����"), helpMenu);
	QAction *about = new QAction(tr("����"), helpMenu); 
	connect(inMap, SIGNAL(triggered()), this, SLOT(setMap()));
	connect(help, SIGNAL(triggered()), this, SLOT(showHelp()));
	connect(about, SIGNAL(triggered()), this, SLOT(showAbout()));
	connect(startGame, SIGNAL(triggered()), this, SLOT(startGame()));
	connect(autoGame, SIGNAL(triggered()), this, SLOT(autoGame()));
	connect(quitGame, SIGNAL(triggered()), this, SLOT(quitGame()));
	gameMenu->addAction(startGame);
	gameMenu->addAction(inMap);
	gameMenu->addAction(autoGame);
	gameMenu->addAction(quitGame);
	helpMenu->addAction(help);
	helpMenu->addAction(about);
	menuBar->addMenu(gameMenu);
	menuBar->addMenu(helpMenu);
	setMenuBar(menuBar);
}

void MyClass::startGame()
{
	if (isIn){
		isRun = true;
		beginSound->stop();
		runSound->play();
		update();
	}
	else
		QMessageBox::critical(this, tr("����"),
		tr("û�е����ͼ."));
}

void MyClass::showHelp()
{
	QMessageBox::information(this, tr("Help"),
		tr("�ȵ����ͼ,Ȼ���ٿ�ʼ��Ϸ\n�����������ҿ���\n��ʼ��Ϸ������Զ�Ѱ·\n�Զ�Ѱ·��ʱ�������궼��Ҫ��,��Ȼ���ܿ�ס."));
}

void MyClass::showAbout()
{
	QMessageBox::information(this, tr("About"),
		tr("�Զ�������1.0\n          by Aesma"));
}

void MyClass::setMap()
{
	if (isRun){
		QMessageBox::information(this, tr("ע��"),
			tr("������Ϸ\n���˳���Ϸ���ٵ����ͼ."));
		return;
	}
	if (isIn){
		delete pushBox;
		mapH = 0;
		mapW = 0;
	}
	QString filePath = QFileDialog::getOpenFileName(
		this,
		"Open Document",
		QDir::currentPath(),
		"Document(*.txt)");
	if (filePath == ""){
		QMessageBox::warning(this, tr("Error"),
			tr("û��ѡ���ͼ!"));
		return;
	}
	QFile mapFile(filePath);
	mapFile.open(QIODevice::ReadOnly);
	QString str = mapFile.readLine();
	mapW = str.size() - 2;
	mapFile.seek(0);
	while (!mapFile.atEnd()){
		mapFile.readLine();
		mapH++;
	}
	mapFile.seek(0);
	isRood = new bool*[mapW];
	for (int i = 0; i < mapW; i++)
		isRood[i] = new bool[mapH];
	for (int i = 0; i < mapW; i++)
	for (int j = 0; j < mapH; j++)
		isRood[i][j] = true;
	int count = 0;
	while (!mapFile.atEnd()){
		QByteArray byte = mapFile.readLine();
		for (int i = 0; i < mapW; i++)
		{
			if (byte[i] == '-')
				isRood[i][count] = false;
			else if (byte[i] == 'A'){
				man.x = i;
				man.y = count;
			}
			else if (byte[i] == 'X'){
				box.x = i;
				box.y = count;
			}
			else if (byte[i] == 'O'){
				end.x = i;
				end.y = count;
			}
		}
		count++;
	}
	pushBox = new PushBox(mapW, mapH, isRood, box, man, end);
	
	isIn = true;
	QMessageBox::information(this, tr("Success"),
		tr("��ȡ��ͼ�ɹ�."));
}

MyClass::~MyClass()
{
	
}
