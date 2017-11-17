#ifndef DISKDIALOG_H
#define DISKDIALOG_H

#include "Disk.h"
#include "ui_disk.h"

#include <QFileDialog>
#include <QFile>

class DiskDialog :public QDialog, public Ui_diskDialog
{
	Q_OBJECT
public:
	DiskDialog(QWidget *parent = 0);
	~DiskDialog();
private slots:
	void doDisk();
	void openFile();
private:
	QString filePath;
};

#endif