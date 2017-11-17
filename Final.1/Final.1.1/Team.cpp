#include "Team.h"

TeamClass::TeamClass(QString path)
{
	count = 0;
	filePath = path;
	file.setFileName(filePath);
	outFile.setFileName("�������.txt");
	outFile.open(QIODevice::Text | QIODevice::WriteOnly);
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString str;
	in >> str;
	QStringList l = str.split(",");
	N = l[0].toInt();
	M = l[1].toInt();
	for (int i = 0; i < N; i++)
	{
		graph.insertVertex(i);
	}
	while (!in.atEnd()){
		QString temp;
		in >> temp;
		QStringList list = temp.split(",");
		QByteArray t1 = list[0].toLocal8Bit();
		QByteArray t2 = list[1].toLocal8Bit();
		int team1 = t1[1] - '0';
		int team2 = t2[1] - '0';
		if (graph.getWeight(team1 - 1, team2 - 1) == maxWeight){
			graph.insertEdge(team1 - 1, team2 - 1, 1);
		}
	}
	QTextStream out(&outFile);
	out << '\0' << '\0' << '\0' << '\n';
}

void TeamClass::outCount()
{
	outFile.seek(0);
	outFile.open(QIODevice::Text | QIODevice::WriteOnly);
	QTextStream out(&outFile);
	out << count << '\n';
}

void TeamClass::tSort()
{
	QByteArray byte;
	TopologicalSort(graph, byte);
}

void TeamClass::TopologicalSort(Graphmtx g,QByteArray nodes)
{
	queue<int> q;
	for (int i = 0; i < g.NumberOfVertices(); i++)//��ͼ�е�i������Ƿ���ǰ����㣬���û�У��ʹ��������
	{
		bool pre = false;
		for (int j = 0; j < g.NumberOfVertices(); j++)
		{
			int temp = g.getWeight(j, i);
			if (j != i&&temp == 1){
				pre = true;
				break;
			}
		}
		if (!pre)
			q.push(i);
	}
	while (!q.empty()){
		int v = q.front();
		q.pop();
		nodes.append('p' + QString::number(g.getValue(v) + 1) + ',');
		Graphmtx g2 = g;
		g2.removeVertex(v);
		if (g2.GraphEmpty()){
			QTextStream out(&outFile);
			nodes = nodes.left(nodes.length() - 1);
			out << nodes << "\n";
			count++;
		}
		else{
			TopologicalSort(g2, nodes);
			nodes = nodes.left(nodes.length() - 3);
		}
	}
}

TeamClass::~TeamClass()
{
	file.close();
	outFile.close();
}