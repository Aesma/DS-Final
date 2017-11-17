#include "Subway.h"

Subway::Subway(QString path)
{
	siteCount = 0;
	filePath = path;
	excel = new QAxObject("Excel.Application");
	excel->setProperty("Visible", false); 
	QAxObject *workbooks = excel->querySubObject("WorkBooks");
	QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", filePath);
	QAxObject *worksheets = workbook->querySubObject("WorkSheets");
	sheetCount = worksheets->property("Count").toInt();
	QAxObject *worksheet;

	for (int i = 1; i <= sheetCount; i++)
	{
		worksheet = workbook->querySubObject("WorkSheets(int)", i);
		QAxObject * usedrange = worksheet->querySubObject("UsedRange");
		QAxObject * rows = usedrange->querySubObject("Rows");
		int intRows = rows->property("Count").toInt();
		siteCount += (intRows - 2);
	}
	siteCount *= 2;
	
	sites = new Site[siteCount];
	int temp = 1;

	for (int i = 1; i <= sheetCount; i++)
	{
		worksheet = workbook->querySubObject("WorkSheets(int)", i);
		QString line = worksheet->property("Name").toString();
		QAxObject * usedrange = worksheet->querySubObject("UsedRange");
		QAxObject * rows = usedrange->querySubObject("Rows");
		int intRows = rows->property("Count").toInt();
		for (int j = 3; j <= intRows; j++)
		{
			QAxObject *cell = worksheet->querySubObject("Cells(int,int)", j, 1);
			QVariant cell_value = cell->dynamicCall("Value2()");
			QString FromTo = cell_value.toString();
			QStringList bet = FromTo.split("——");

			for (int k = 0; k < temp; k++)
			{
				if (sites[k].name == bet[0]){
					bool add = false;
					for (int m = 0; m < sites[k].path.size(); m++)
					{
						add = true;
						if (sites[k].path[m] == line)
							add = false;
					}
					if (add){
						sites[k].path.append(line);
						sites[k].isChange = true;
					}
					break;
				}
				else if (k == temp - 1){
					sites[k].path.append(line);
					sites[k].name = bet[0];
					temp++;
					break; 
				}
			}
			for (int k = 0; k < temp; k++)
			{
				if (sites[k].name == bet[1]){
					bool add = false;
					for (int m = 0; m < sites[k].path.size(); m++)
					{
						add = true;
						if (sites[k].path[m] == line)
							add = false;
					}
					if (add){
						sites[k].path.append(line);
						sites[k].isChange = true;
					}
					break;
				}
				else if (k == temp - 1){
					sites[k].path.append(line);
					sites[k].name = bet[1];
					temp++;
					break;
				}
			}
		}
	}

	temp--;
	graph = new Graphmtx(temp);
	siteCounts = temp;

	for (int i = 0; i < temp; i++)
		graph->insertVertex(sites[i]);

	QFile *edgeFile = new QFile("./data/edge.dat");
	bool a=edgeFile->open(QIODevice::WriteOnly);
	QDataStream outEdge(edgeFile);

	for (int i = 1; i <= sheetCount; i++)
	{
		worksheet = workbook->querySubObject("WorkSheets(int)", i);
		QAxObject * usedrange = worksheet->querySubObject("UsedRange");
		QAxObject * rows = usedrange->querySubObject("Rows");
		int intRows = rows->property("Count").toInt();
		for (int j = 3; j < intRows; j++)
		{
			QAxObject *cell = worksheet->querySubObject("Cells(int,int)", j, 1);
			QVariant cell_value = cell->dynamicCall("Value2()");
			QString FromTo = cell_value.toString();
			QStringList bet = FromTo.split("——");
			cell = worksheet->querySubObject("Cells(int,int)", j, 2);
			int length = cell->dynamicCall("Value2()").toInt();
			int v1 = graph->getVertexPos(bet[0]);
			int v2 = graph->getVertexPos(bet[1]);
			graph->insertEdge(v1, v2, length);
			outEdge << v1 << v2 << length;
		}
	}

	edgeFile->close();

	workbook->dynamicCall("Close(Boolean)", false);  //关闭文件
	excel->dynamicCall("Quit(void)");  //退出

	QFile *file = new QFile("./data/vertices.dat");
	file->open(QIODevice::Text | QIODevice::WriteOnly);
	QTextStream out(file);
	out << siteCounts << '\n';
	for (int i = 0; i < siteCounts; i++)
	{
		out << sites[i].isChange << '\n' << sites[i].name << '\n' << sites[i].path.size() << '\n';
		for (int j = 0; j < sites[i].path.size(); j++)
			out << sites[i].path[j] << '\n';
	}
	file->close();
}

Subway::Subway()
{
	QFile *file = new QFile("./data/vertices.dat");
	file->open(QIODevice::Text | QIODevice::ReadOnly);
	QTextStream in(file);
	in >> siteCounts;
	graph = new Graphmtx(siteCounts);
	sites = new Site[siteCounts];
	for (int i = 0; i < siteCounts; i++)
	{
		int size;
		int change;
		in >> change >> sites[i].name;
		in >> size;
		sites[i].isChange = change;
		for (int j = 0; j < size; j++)
		{
			QString str;
			in >> str;
			sites[i].path.append(str);
		}
		graph->insertVertex(sites[i]);
	}
	file->close();
	QFile *edgeFile = new QFile("./data/edge.dat");
	edgeFile->open(QIODevice::ReadOnly);
	QDataStream inEdge(edgeFile);
	while (!inEdge.atEnd()){
		int v1, v2, cost;
		inEdge >> v1 >> v2 >> cost;
		graph->insertEdge(v1, v2, cost);
	}
	edgeFile->close();
}

void Subway::addEdge(QString v1, QString v2, int cost)
{
	int intv1 = graph->getVertexPos(v1);
	int intv2 = graph->getVertexPos(v2);
	if (intv1 == -1 || intv2 == -1){
		QMessageBox::critical(NULL, "Error",
			"添加线路失败,某个站点不存在.");
		return;
	}
	graph->insertEdge(intv1, intv2, cost);
}

void Subway::delEdge(QString v1, QString v2)
{
	int intv1 = graph->getVertexPos(v1);
	int intv2 = graph->getVertexPos(v2);
	if (intv1 == -1 || intv2 == -1){
		QMessageBox::critical(NULL, "Error",
			"删除线路失败,某个站点不存在.");
		return;
	}
	graph->removeEdge(intv1, intv2);
}

void Subway::addVertice(QString s)
{
	Site site;
	site.name = s;
	graph->insertVertex(site);
}

void Subway::delVertice(QString s)
{
	int v = graph->getVertexPos(s);
	if (v == -1){
		QMessageBox::critical(NULL, "Error",
			"删除站点失败,该站点不存在.");
		return;
	}
	graph->removeVertex(v);
}

QStringList Subway::searchEdge(QString e)
{
	QStringList list;
	for (int i = 0; i < siteCounts; i++)
	for (int j = 0; j < sites[i].path.size(); j++)
	{
		if (sites[i].path[j] == e){
			list.append(sites[i].name);
			break;
		}
	}
	if (list.size() == 0)
		QMessageBox::information(NULL, "",
		"不存在该线路.");
	return list;
}

QStringList Subway::searchVertice(QString s)
{
	QStringList list;
	int v = graph->getVertexPos(s);
	if (v == -1){
		QMessageBox::information(NULL, "",
			"不存在该站点.");
		return list;
	}
	Site site = graph->getValue(v);
	for (int i = 0; i < site.path.size(); i++)
	{
		list.append(site.path[i]);
	}
	return list;
}

QList<Node> Subway::getMinLenPlan(QString v1,QString v2)
{
	QList<Node>nodeList;
	int v = graph->getVertexPos(v1);
	int w = graph->getVertexPos(v2);
	if (v == -1 || w == -1){
		QMessageBox::information(NULL, "",
			"至少有一个站点不存在.");
		return nodeList;
	}
	ShortestPath(*graph, v);
	int m = w;
	while (w != v){
		Node node;
		Site temp = graph->getValue(w);
		node.stop = temp.name; 
		node.isChange = temp.isChange;
		node.len = graph->getWeight(w, path[w]);
		if (!node.isChange)
			node.path = temp.path[0];
		else{
			temp = graph->getValue(path[w]);
			node.path = temp.path[0];	
			temp = graph->getValue(m);
			node.path += ("->" + temp.path[0]);
		}
		nodeList.append(node);
		m = w;
		w = path[w];		
	}
	Site temp = graph->getValue(w);
	Node node;
	node.stop = temp.name;
	node.path = temp.path[0];
	nodeList.append(node);

	return nodeList;
}

void Subway::ShortestPath(Graphmtx& G, int v)
{
	int n = G.NumberOfVertices();
	bool *S = new bool[n];
	dist = new int[n];
	path = new int[n];
	int w, min;
	for (int i = 0; i < n; i++)
	{
		dist[i] = G.getWeight(v, i);
		S[i] = false;
		if (i != v&&dist[i] < maxWeight)
			path[i] = v;
		else
			path[i] = -1;
	}
	S[v] = true;
	dist[v] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min = maxWeight;
		int u = v;
		for (int j = 0; j < n; j++)
		if (!S[j] && dist[j] < min){
			u = j;
			min = dist[j];
		}
		S[u] = true;
		for (int k = 0; k < n; k++)
		{
			w = G.getWeight(u, k);
			if (!S[k] && w < maxWeight&&dist[u] + w < dist[k]){
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
}

Subway::~Subway()
{
	delete[]path;
	delete[]dist;
	delete[]sites;
}