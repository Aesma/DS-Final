#include "Disk.h"

Disk::Disk(QString path)
{
	filePath = path;
	file.setFileName(filePath);
	file.open(QIODevice::ReadOnly);
	in.setDevice(&file);
	in >> N >> K;
	logic = new Logic[N + 1];
	times = 0;
	sum = 0;
	int count = 1;
	while (!in.atEnd()){
		int temp;
		in >> temp;
		sum += temp;
		for (int i = 0; i < temp; i++)
		{
			int temp2;
			in >> temp2;
			logic[temp2].num = count;
			logic[temp2].use = true;
			count++;
		}
	}
}

void Disk::Arrange()
{
	doArr(1);
}

void Disk::doArr(int i)
{
	if (i > N)
		return;
	if (logic[i].use&&i != logic[i].num){
		int temp = logic[i].num;
		swap(logic[i].num, logic[temp].num);
		times++;
		logic[temp].FromTo += (QString::number(i) + "->" + QString::number(temp) + " ");
		if (logic[temp].use){
			logic[logic[i].num].FromTo += (QString::number(temp) + "->" + QString::number(i) + " ");
			doArr(i);
		}
		else{
			logic[i].use = false;
			logic[i].num = 0;
			doArr(i + 1);
		}
	}
	else
		doArr(i + 1);
}

void Disk::outPut()
{
	QString outFile = "整理结果.txt";
	QFile newFile(outFile);
	newFile.open(QIODevice::Text | QIODevice::WriteOnly);
	QTextStream out(&newFile);
	out << times << '\n';
	int i = 1;
	while (1){
		if (logic[i].num){
			out << logic[i].FromTo << '\n';
		}
		i++;
		if (i == N)
			break;
	}
	newFile.close();
}

int Disk::getTimes()
{
	return times;
}

Disk::~Disk()
{
	file.close();
}