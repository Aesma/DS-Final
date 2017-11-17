/**
这个直接把暑假的代码稍微改了一下 格式就不要在意啦
*/

#ifndef QCALCULATE_H
#define QCALCULATE_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>

#include "ui_Wood.h"
#include "QtHead.h"

struct Wood
{
	Wood() :vis(false){};
	int length;
	int weigth;
	bool vis;
	bool operator <(Wood w)const;
};

class Calculate :public QDialog, public Ui::Form
{
	Q_OBJECT
public:
	Calculate(QWidget *pareant = 0);
	~Calculate();
private slots:
	void SetWoods();
	void Polishing();
private:
	int *time;
	int *pieces;
	int groups;
	int sum;
	Wood **woods;
	QString filepath;
};
#endif