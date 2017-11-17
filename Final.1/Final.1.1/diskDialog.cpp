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
			tr("û��ѡ���ļ�!"));
		return;
	}
	lineEdit->setText(filePath);
	QMessageBox::information(this, tr("Success"),
		tr("��ȡ�ļ��ɹ�."));
}

void DiskDialog::doDisk()
{
	if (filePath == ""){
		QMessageBox::warning(this, tr("Error"),
			tr("û�ж�ȡ�ļ�!"));
		return;
	}
	Disk disk(filePath);
	disk.Arrange(); 
	disk.outPut();
	QMessageBox::information(this, tr("Success"),
		tr("������Ƭ���\n��д���ļ�:������.txt."));
}

DiskDialog::~DiskDialog()
{

}