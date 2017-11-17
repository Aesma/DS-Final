#include "diskDialog.h"

DiskDialog::DiskDialog(QWidget *parent)
: QDialog(parent)
{
	setupUi(this);

	connect(inButton, SIGNAL(clicked()), this, SLOT(openFile()));
	connect(doButton, SIGNAL(clicked()), this, SLOT(doDisk()));
}

void DiskDialog::openFile()
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

void DiskDialog::doDisk()
{
	if (filePath == ""){
		QMessageBox::warning(this, tr("Error"),
			tr("没有读取文件!"));
		return;
	}
	Disk disk(filePath);
	disk.Arrange(); 
	disk.outPut();
	QMessageBox::information(this, tr("Success"),
		tr("整理碎片完成\n已写入文件:整理结果.txt."));
}

DiskDialog::~DiskDialog()
{

}