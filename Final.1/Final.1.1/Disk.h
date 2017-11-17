#ifndef DISK_H
#define DISK_H

#include "QtHead.h"

struct Logic
{
	int num;
	bool use;
	QString FromTo;
	Logic(int n = 0, bool u = false){ num = n; use = u;};
};

class Disk
{
public:
	Disk(QString path);
	int getTimes();
	void outPut();
	void Arrange();
	void doArr(int n);
	~Disk();
private:
	QString filePath;
	QFile file;
	Logic *logic;
	QTextStream in;
	int N;
	int K;
	int times;
	int sum;
};


#endif