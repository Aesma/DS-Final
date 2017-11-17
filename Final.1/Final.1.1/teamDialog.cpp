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
			tr("û��ѡ���ļ�!"));
		return;
	}
	lineEdit->setText(filePath);
	QMessageBox::information(this, tr("Success"),
		tr("��ȡ�ļ��ɹ�."));
}

void TeamDialog::tSort()
{
	if (filePath == ""){
		QMessageBox::warning(this, tr("Error"),
			tr("û��ѡ���ļ�!"));
		return;
	};
	TeamClass team(filePath);
	team.tSort();
	team.outCount();
	QMessageBox::information(this, tr("Success"),
		tr("�������.\n������д���ļ� ������.txt."));
}

TeamDialog::~TeamDialog()
{

}