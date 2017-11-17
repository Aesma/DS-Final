#include "teamDialog.h"

TeamDialog::TeamDialog(QWidget *parent)
: QDialog(parent)
{
	setupUi(this);

	connect(inButton, SIGNAL(clicked()), this, SLOT(openFile()));
	connect(doButton, SIGNAL(clicked()), this, SLOT(tSort()));
}

void TeamDialog::openFile()
{
	filePath = QFileDialog::getOpenFileName(
		this,
		"Open Document",
		QDir::currentPath(),
		"Document(*.txt)");
	if (filePath == ""){
		QMessageBox::warning(this, tr("Error"),
			tr("没有选择文件!"));
		return;
	}
	lineEdit->setText(filePath);
	QMessageBox::information(this, tr("Success"),
		tr("读取文件成功."));
}

void TeamDialog::tSort()
{
	if (filePath == ""){
		QMessageBox::warning(this, tr("Error"),
			tr("没有选择文件!"));
		return;
	};
	TeamClass team(filePath);
	team.tSort();
	team.outCount();
	QMessageBox::information(this, tr("Success"),
		tr("排序完成.\n并且已写入文件 排序结果.txt."));
}

TeamDialog::~TeamDialog()
{

}