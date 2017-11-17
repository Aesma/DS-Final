#include "Everything.h"

Everything::Everything()
{

}

void Everything::creatIndex()
{
	fileV.clear();
	QDir dir;
	file = new QFile("index.ini");
	file->open(QIODevice::Text | QIODevice::WriteOnly);
	QFileInfoList disks = dir.drives();
	for (int i = 0; i < disks.size(); i++)
	{
		QString path = disks[i].filePath();
		findFile(path);
	}
	file->close();
}

void Everything::getIndex()
{
	QFile file("index.ini");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	while (!in.atEnd()){
		fileNode node;
		in >> node.fileName >> node.filePath >> node.fileSize;
		fileV.append(node);
	}
	file.close();
}

bool Everything::findFile(QString path)
{
	QTextStream out(file);
	QDir dir(path);
	if (!dir.exists())
		return false;
	QStringList filters;
	filters << QString("*.*");
	QDirIterator dir_iterator(path,
		filters,
		QDir::Files | QDir::NoSymLinks,
		QDirIterator::Subdirectories);
	while (dir_iterator.hasNext())
	{
		dir_iterator.next();
		QFileInfo file_info = dir_iterator.fileInfo();
		fileNode f;
		f.filePath = file_info.absoluteFilePath();
		f.fileName = file_info.fileName();
		f.fileSize = file_info.size();
		fileV.append(f);
		out << f.fileName << '\n' << f.filePath << '\n' << f.fileSize << '\n';
	}

}

void Everything::search(QString name)
{
	for (int i = 0; i < fileV.size(); i++)
	{
		if (fileV[i].fileName.contains(name, Qt::CaseSensitive)||
			fileV[i].filePath.contains(name, Qt::CaseSensitive))
			result.append(fileV[i]);
	}
}

QVector<fileNode>Everything::getResult()
{
	return result;
}

void Everything::clearResult()
{
	result.clear();
}

Everything::~Everything()
{

}