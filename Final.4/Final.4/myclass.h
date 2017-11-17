#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include <QSound>
#include <QMenu>
#include <QMenuBar>
#include <QFile>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "ui_myclass.h"
#include "PushBox.h"

class MyClass : public QMainWindow,public Ui_MyClassClass
{
	Q_OBJECT

public:
	MyClass(QWidget *parent = 0);
	~MyClass();
protected:
	void keyPressEvent(QKeyEvent *event);
	void paintEvent(QPaintEvent *event);
private slots:
	void setMap();
	void showAbout();
	void showHelp();
	void startGame();
	void autoSlot();
	void autoGame();
	void quitGame();
private:
	void creatMenu();
private:
	int direct;
	int menuBarSize;
	int mapW;
	int mapH;
	bool isRun;
	bool isIn;
	bool **isRood;
	Node man;
	Node box;
	Node end;
	PushBox *pushBox;
	QMediaPlayer *beginSound;
	QMediaPlayer *runSound;
	QMediaPlayer *loseSound;
	QMediaPlayer *winSound;
	QPixmap *wall;
	QPixmap *manPix;
	QPixmap *ground;
	QPixmap *goal;
	QPixmap *boxPix;
};

#endif // MYCLASS_H
