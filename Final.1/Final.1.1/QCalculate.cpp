#include <QtGui>

#include "QCalculate.h"
#include <QMessageBox>

bool Wood::operator <(Wood w)const
{
	if (length < w.length&&weigth < w.weigth){
		return true;
	}
	else{
		return false;
	}
}

Calculate::Calculate(QWidget *parent)
:QDialog(parent)
{
	setupUi(this);

	connect(InputButton, SIGNAL(clicked()), this, SLOT(SetWoods()));
	connect(CalButton, SIGNAL(clicked()), this, SLOT(Polishing()));
	sum = 0;
}

bool com(Wood &a, Wood &b)
{
	if (a.length < b.length)
		return true;
	else
		return false;
}

void Calculate::SetWoods()
{
	filepath = QFileDialog::getOpenFileName(
		this,
		"Open Document", 
		QDir::currentPath(),
		"Document files (*.txt);;All files(*.*)");
	InputLine->setText(filepath);
	QFile infile(filepath);
	if (!infile.open(QIODevice::ReadWrite | QIODevice::Text)){
		QMessageBox::warning(this, tr("Polishing"),
			tr("Cannot read file %1:\n%2.").arg(infile.fileName())
			.arg(infile.errorString()));
		return;
	}
	else{
		QTextStream in(&infile);
		in >> groups;
		woods = new Wood*[groups];
		time = new int[groups];
		pieces = new int[groups];
		for (int i = 0; i < groups; i++)
		{
			in >> pieces[i];
			woods[i] = new Wood[pieces[i]];
			time[i] = 0;
			for (int j = 0; j < pieces[i]; j++)
			{
				in >> woods[i][j].length;
				in >> woods[i][j].weigth;
			}
		}
	}
	infile.close();
	QMessageBox::information(this, tr("Success"),
		tr("读取文件完成."));
}

void Calculate::Polishing()
{
	if (filepath == ""){
		QMessageBox::warning(this, tr("Polishing"),
			tr("Cannot read file."));
		return;
	}
	tableWidget->setColumnCount(2);
	tableWidget->setRowCount(groups);
	tableWidget->setHorizontalHeaderLabels(QStringList() << "Time" << "Order");
	for (int i = 0; i < groups; i++)
	{
 		QString order;
		std::sort(woods[i], woods[i] + pieces[i], com);
		Wood tem_wood;
		bool isBreak = false;
		while (!isBreak){
			int begin;
			for (int j = 0; j < pieces[i]; j++)
			{
				if (!woods[i][j].vis){
					tem_wood = woods[i][j];
					order += ('(' + QString::number(woods[i][j].length) + ',' + QString::number(woods[i][j].weigth) + ')');
					woods[i][j].vis = true;
					begin = j;
					break;
				}
			}
			for (int j = begin + 1; j < pieces[i]; j++)
			{
				if (!woods[i][j].vis&&tem_wood < woods[i][j]){
					order += ('(' + QString::number(woods[i][j].length) + ',' + QString::number(woods[i][j].weigth) + ')');
					tem_wood = woods[i][j];
					woods[i][j].vis = true;
				}
			}
			time[i]++;
			sum++;
			for (int j = 0; j < pieces[i]; j++)
			{
				isBreak = true;
				if (!woods[i][j].vis){
					isBreak = false;
					break;
				}
			}
		}
		QString temp = QString::number(time[i]);
		tableWidget->setItem(i, 0, new QTableWidgetItem(temp));
		tableWidget->setItem(i, 1, new QTableWidgetItem(order));
	}
	tableWidget->resizeColumnToContents(0);
	tableWidget->resizeColumnToContents(1);
	QString total = QString::number(sum) + ".";
	QMessageBox::information(this, tr("Success"),
		"木材抛光完成\n总时间为" + total);
}

Calculate::~Calculate()
{

}