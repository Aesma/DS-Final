#include "listDialog.h"

ListDialog::ListDialog(QWidget *parent)
: QDialog(parent)
{
	setupUi(this);

	dealSheet();
	connect(listButton, SIGNAL(clicked()), this, SLOT(doList()));
}

void ListDialog::doList()
{
	for (int i = 0; i < 5; i++)
	{
		list.Insert(i, i + 65);
	}
	list.Link(0, 2);
	list.Link(1, 4);
	list.Link(3, 1);
	Node *copy = list.Copy();
	QMessageBox::information(this, tr("Success"),
		tr("链表复制成功."));
	int count = 0;

	while (copy != nullptr){
		tableWidget->setItem(count, 0, new QTableWidgetItem(QString(copy->data)));
		if (copy->next == nullptr)
			tableWidget->setItem(count, 1, new QTableWidgetItem("NULL"));
		else
			tableWidget->setItem(count, 1, new QTableWidgetItem(QString(copy->next->data)));
		if (copy->random == NULL)
			tableWidget->setItem(count, 2, new QTableWidgetItem("NULL"));
		else
			tableWidget->setItem(count, 2, new QTableWidgetItem(QString(copy->random->data)));
		copy = copy->next;
		count++;
	}
}

void ListDialog::dealSheet()
{
	tableWidget->setRowCount(5);
	tableWidget->setColumnCount(3);
	QStringList head;
	head << "Data" << "Next" << "Random";
	tableWidget->setHorizontalHeaderLabels(head);
}

ListDialog::~ListDialog()
{

}