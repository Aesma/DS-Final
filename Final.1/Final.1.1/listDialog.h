#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include "List.h"
#include "ui_list.h"
#include <QDialog>

class ListDialog :public QDialog, public Ui::listDialog
{
	Q_OBJECT
public:
	ListDialog(QWidget *parent = 0);
	~ListDialog();
private slots:
	void doList();
private:
	void dealSheet();
private:
	List list;
};

#endif