#ifndef TEAMDIALOG_H
#define TEAMDIALOG_H

#include "ui_team.h"
#include "Team.h"
#include <QDialog>
#include <QFileDialog>

class TeamDialog :public QDialog, public Ui_teamDialog
{
	Q_OBJECT
public:
	TeamDialog(QWidget *parent = 0);
	~TeamDialog();
private slots:
	void openFile();
	void tSort();
private:
	QString filePath;
};

#endif