#include "PushBox.h"

PushBox::PushBox(int w, int h, bool **r, Node b, Node m, Node e)
{
	director = 0;
	mapW = w;
	mapH = h;
	isRood = new bool*[mapW];
	for (int i = 0; i < mapW; i++)
		isRood[i] = new bool[mapH];
	for (int i = 0; i < mapW; i++)
	for (int j = 0; j < mapH; j++)
	{
		isRood[i][j] = r[i][j];
	}
	box = b;
	man = m;
	end = e;
	isWin = false;
}

Node PushBox::getBox()
{
	return box;
}

Node PushBox::getMan()
{
	return man;
}

bool PushBox::judge()
{
	if (box.x == end.x&&box.y == end.y)
		return true;
	return false;
}

void PushBox::move()
{
	int x = man.x;
	int y = man.y;
	if (director == 1){
		y -= 1;
		if (y >= 0){
			if (x == box.x&&y == box.y){
				if (y - 1 >= 0 && isRood[x][y - 1]){
					box.y--;
					man.y--;
				}
			}
			else if (isRood[x][y]){
				man.x = x;
				man.y = y;
			}
		}
	}
	else if (director == 2){
		x += 1;
		if (x < mapW){
			if (x == box.x&&y == box.y){
				if (x + 1 < mapW&&isRood[x + 1][y]){
					box.x++;
					man.x++;
				}
			}
			else if (isRood[x][y]){
				man.x = x;
				man.y = y;
			}
		}
	}
	else if (director == 3){
		y += 1;
		if (y < mapH){
			if (x == box.x&&y == box.y){
				if (y + 1 <= mapH&&isRood[x][y + 1]){
					box.y++;
					man.y++;
				}
			}
			else if (isRood[x][y]){
				man.x = x;
				man.y = y;
			}
		}
	}
	else if (director == 4){
		x -= 1;
		if (x >= 0){
			if (x == box.x&&y == box.y){
				if (x - 1 >= 0 && isRood[x - 1][y]){
					box.x--;
					man.x--;
				}
			}
			else if (isRood[x][y]){
				man.x = x;
				man.y = y;
			}
		}
	}
	isWin = judge();
	director = 0;
}

void PushBox::changeDirect(int i)
{
	director = i;
	move();
}

bool PushBox::getResult()
{
	return isWin;
}

bool PushBox::calBoxBfs(Node st, Node en)
{
	while (!boxQue.empty())
		boxQue.pop();
	queue<Node>temQue;
	bool **visit = new bool*[mapW];
	for (int i = 0; i < mapW; i++)
		visit[i] = new bool[mapH];
	for (int i = 0; i < mapW; i++)
	for (int j = 0; j < mapH; j++)
		visit[i][j] = false;
	visit[st.x][st.y] = true;
	Node head, next;
	int quesize;
	temQue.push(st);
	while (!temQue.empty()){
		quesize = temQue.size();
		while (quesize--){
			bool **flagMan = new bool*[mapW];
			for (int i = 0; i < mapW; i++)
				flagMan[i] = new bool[mapH];
			for (int i = 0; i < mapW; i++)
			for (int j = 0; j < mapH; j++)
				flagMan[i][j] = false;
			flagMan[man.x][man.y] = true;
			stack<Node>s;
			s.push(man);
			head = temQue.front();
			while (!s.empty()){
				Node temp;
				temp = s.top();
				s.pop();
				if (temp.x > 0 && temp.x < mapW - 1 && temp.y>0 && temp.y < mapH - 1){
					if (isRood[temp.x][temp.y - 1] && !(temp.x == head.x&&temp.y - 1 == head.y) && !flagMan[temp.x][temp.y - 1]){
						flagMan[temp.x][temp.y - 1] = true;
						Node temp2 = temp;
						temp2.y--;
						s.push(temp2);
					}
					if (isRood[temp.x + 1][temp.y] && !(temp.x + 1 == head.x&&temp.y == head.y) && !flagMan[temp.x + 1][temp.y]){
						flagMan[temp.x + 1][temp.y] = true;
						Node temp2 = temp;
						temp2.x++;
						s.push(temp2);
					}
					if (isRood[temp.x][temp.y + 1] && !(temp.x == head.x&&temp.y + 1 == head.y) && !flagMan[temp.x][temp.y + 1]){
						flagMan[temp.x][temp.y + 1] = true;
						Node temp2 = temp;
						temp2.y++;
						s.push(temp2);
					}
					if (isRood[temp.x - 1][temp.y] && !(temp.x - 1 == head.x&&temp.y == head.y) && !flagMan[temp.x - 1][temp.y]){
						flagMan[temp.x - 1][temp.y] = true;
						Node temp2 = temp;
						temp2.x--;
						s.push(temp2);
					}
				}
				else if (temp.x == 0){
					if (temp.y > 0 && temp.y < mapH){
						if (isRood[temp.x][temp.y - 1] && !(temp.x == head.x&&temp.y - 1 == head.y) && !flagMan[temp.x][temp.y - 1]){
							flagMan[temp.x][temp.y - 1] = true;
							Node temp2 = temp;
							temp2.y--;
							s.push(temp2);
						}
						if (isRood[temp.x + 1][temp.y] && !(temp.x + 1 == head.x&&temp.y == head.y) && !flagMan[temp.x + 1][temp.y]){
							flagMan[temp.x + 1][temp.y] = true;
							Node temp2 = temp;
							temp2.x++;
							s.push(temp2);
						}
						if (isRood[temp.x][temp.y + 1] && !(temp.x == head.x&&temp.y + 1 == head.y) && !flagMan[temp.x][temp.y + 1]){
							flagMan[temp.x][temp.y + 1] = true;
							Node temp2 = temp;
							temp2.y++;
							s.push(temp2);
						}
					}
					else if (temp.y == 0){
						if (isRood[temp.x + 1][temp.y] && !(temp.x + 1 == head.x&&temp.y == head.y) && !flagMan[temp.x + 1][temp.y]){
							flagMan[temp.x + 1][temp.y] = true;
							Node temp2 = temp;
							temp2.x++;
							s.push(temp2);
						}
						if (isRood[temp.x][temp.y + 1] && !(temp.x == head.x&&temp.y + 1 == head.y) && !flagMan[temp.x][temp.y + 1]){
							flagMan[temp.x][temp.y + 1] = true;
							Node temp2 = temp;
							temp2.y++;
							s.push(temp2);
						}
					}
					else if (temp.y == mapH - 1){
						if (isRood[temp.x][temp.y - 1] && !(temp.x == head.x&&temp.y - 1 == head.y) && !flagMan[temp.x][temp.y - 1]){
							flagMan[temp.x][temp.y - 1] = true;
							Node temp2 = temp;
							temp2.y--;
							s.push(temp2);
						}
						if (isRood[temp.x + 1][temp.y] && !(temp.x + 1 == head.x&&temp.y == head.y) && !flagMan[temp.x + 1][temp.y]){
							flagMan[temp.x + 1][temp.y] = true;
							Node temp2 = temp;
							temp2.x++;
							s.push(temp2);
						}
					}
				}
				else if (temp.x == mapW - 1){
					if (temp.y > 0 && temp.y < mapH){
						if (isRood[temp.x][temp.y - 1] && !(temp.x == head.x&&temp.y - 1 == head.y) && !flagMan[temp.x][temp.y - 1]){
							flagMan[temp.x][temp.y - 1] = true;
							Node temp2 = temp;
							temp2.y--;
							s.push(temp2);
						}
						if (isRood[temp.x][temp.y + 1] && !(temp.x == head.x&&temp.y + 1 == head.y) && !flagMan[temp.x][temp.y + 1]){
							flagMan[temp.x][temp.y + 1] = true;
							Node temp2 = temp;
							temp2.y++;
							s.push(temp2);
						}
						if (isRood[temp.x - 1][temp.y] && !(temp.x - 1 == head.x&&temp.y == head.y) && !flagMan[temp.x - 1][temp.y]){
							flagMan[temp.x - 1][temp.y] = true;
							Node temp2 = temp;
							temp2.x--;
							s.push(temp2);
						}
					}
					else if (temp.y == 0){
						if (isRood[temp.x][temp.y + 1] && !(temp.x == head.x&&temp.y + 1 == head.y) && !flagMan[temp.x][temp.y + 1]){
							flagMan[temp.x][temp.y + 1] = true;
							Node temp2 = temp;
							temp2.y++;
							s.push(temp2);
						}
						if (isRood[temp.x - 1][temp.y] && !(temp.x - 1 == head.x&&temp.y == head.y) && !flagMan[temp.x - 1][temp.y]){
							flagMan[temp.x - 1][temp.y] = true;
							Node temp2 = temp;
							temp2.x--;
							s.push(temp2);
						}
					}
					else if (temp.y == mapH - 1){
						if (isRood[temp.x][temp.y - 1] && !(temp.x == head.x&&temp.y - 1 == head.y) && !flagMan[temp.x][temp.y - 1]){
							flagMan[temp.x][temp.y - 1] = true;
							Node temp2 = temp;
							temp2.y--;
							s.push(temp2);
						}
						if (isRood[temp.x - 1][temp.y] && !(temp.x - 1 == head.x&&temp.y == head.y) && !flagMan[temp.x - 1][temp.y]){
							flagMan[temp.x - 1][temp.y] = true;
							Node temp2 = temp;
							temp2.x--;
							s.push(temp2);
						}
					}
				}
				else if (temp.y == 0){
					if (isRood[temp.x + 1][temp.y] && !(temp.x + 1 == head.x&&temp.y != head.y) && !flagMan[temp.x + 1][temp.y]){
						flagMan[temp.x + 1][temp.y] = true;
						Node temp2 = temp;
						temp2.x++;
						s.push(temp2);
					}
					if (isRood[temp.x][temp.y + 1] && !(temp.x == head.x&&temp.y + 1 == head.y) && !flagMan[temp.x][temp.y + 1]){
						flagMan[temp.x][temp.y + 1] = true;
						Node temp2 = temp;
						temp2.y++;
						s.push(temp2);
					}
					if (isRood[temp.x - 1][temp.y] && !(temp.x - 1 == head.x&&temp.y == head.y) && !flagMan[temp.x - 1][temp.y]){
						flagMan[temp.x - 1][temp.y] = true;
						Node temp2 = temp;
						temp2.x--;
						s.push(temp2);
					}
				}
				else if (temp.y == mapH - 1){
					if (isRood[temp.x][temp.y - 1] && !(temp.x == head.x&&temp.y - 1 == head.y) && !flagMan[temp.x][temp.y - 1]){
						flagMan[temp.x][temp.y - 1] = true;
						Node temp2 = temp;
						temp2.y--;
						s.push(temp2);
					}
					if (isRood[temp.x + 1][temp.y] && !(temp.x + 1 == head.x&&temp.y == head.y) && !flagMan[temp.x + 1][temp.y]){
						flagMan[temp.x + 1][temp.y] = true;
						Node temp2 = temp;
						temp2.x++;
						s.push(temp2);
					}
					if (isRood[temp.x - 1][temp.y] && !(temp.x - 1 == head.x&&temp.y == head.y) && !flagMan[temp.x - 1][temp.y]){
						flagMan[temp.x - 1][temp.y] = true;
						Node temp2 = temp;
						temp2.x--;
						s.push(temp2);
					}
				}
			}
			temQue.pop();
			if (head.x == en.x&&head.y == end.y){
				return true;
			}
			QList<Node>directList = head.boxDirect(flagMan, mapW, mapH);
			for (int i = 0; i < directList.size(); i++)
			{
				next = head + directList[i];
				if (next.x<0 || next.x>mapW - 1 ||
					next.y<0 || next.y>mapH - 1 ||
					!isRood[next.x][next.y]){
					continue;
				}
				if (!visit[next.x][next.y]){
					visit[next.x][next.y] = true;
					temQue.push(next);
					boxParent[next.x][next.y].x = head.x;
					boxParent[next.x][next.y].y = head.y;
				}
			}
			for (int i = 0; i < mapW; i++)
				delete[]flagMan[i];
			delete[]flagMan;
		}
	}
	return false;
}

bool PushBox::calManBfs(Node st, Node en)
{
	while (!manQue.empty())
		manQue.pop();
	int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
	queue<Node>temQue;
	bool **visit = new bool*[mapW];
	for (int i = 0; i < mapW; i++)
		visit[i] = new bool[mapH];
	for (int i = 0; i < mapW; i++)
	for (int j = 0; j < mapH; j++)
		visit[i][j] = false;

	visit[st.x][st.y] = true;
	Node head, next;
	int quesize;
	temQue.push(st);
	while (!temQue.empty()){
		quesize = temQue.size();
		while (quesize--)
		{
			head = temQue.front();
			temQue.pop();
			if (head.x == en.x&&head.y == en.y){
				return true;
			}
			for (int i = 0; i < 4; i++)
			{
				next.x = head.x + dir[i][0];
				next.y = head.y + dir[i][1];
				if (next.x<0 || (next.x>mapW - 1) ||
					next.y<0 || (next.y>mapH - 1) ||
					!isRood[next.x][next.y] ||
					(next.x == box.x&&next.y == box.y)){
					continue;
				}
				if (!visit[next.x][next.y]){
					visit[next.x][next.y] = 1;
					temQue.push(next);
					manParent[next.x][next.y].x = head.x;
					manParent[next.x][next.y].y = head.y;
				}
			}
		}
	}
	return false;
}

void PushBox::calBoxQue(Node en)
{
	if (en.x != -1 && en.y != -1){
		calBoxQue(boxParent[en.x][en.y]);
		boxQue.push(en);
	}
}

void PushBox::calManQue(Node en)
{
	if (en.x != -1 && en.y != -1){
		calManQue(manParent[en.x][en.y]);
		manQue.push(en);
	}
}

bool PushBox::Auto()
{
	boxParent = new Node*[mapW];
	manParent = new Node*[mapW];
	for (int i = 0; i < mapW; i++)
	{
		boxParent[i] = new Node[mapH];
		manParent[i] = new Node[mapH];
	}
	for (int i = 0; i < mapW; i++)
	for (int j = 0; j < mapH; j++)
	{
		boxParent[i][j].x = -1;
		boxParent[i][j].y = -1;
		manParent[i][j].x = -1;
		manParent[i][j].y = -1;
	}
	if (!calBoxBfs(box, end))
		return false;
	calBoxQue(end);
	boxQue.pop();
	Node goal_Box = boxQue.front();
	if (goal_Box.x == box.x&&goal_Box.y < box.y){
		goal_Box.x = box.x;
		goal_Box.y = box.y + 1;
	}
	else if (goal_Box.x > box.x&&goal_Box.y == box.y){
		goal_Box.x = box.x - 1;
		goal_Box.y = box.y;
	}
	else if (goal_Box.x == box.x&&goal_Box.y > box.y){
		goal_Box.x = box.x;
		goal_Box.y = box.y - 1;
	}
	else if (goal_Box.x < box.x&&goal_Box.y == box.y){
		goal_Box.x = box.x + 1;
		goal_Box.y = box.y;
	}
	if (!calManBfs(man, goal_Box))
		return false;
	calManQue(goal_Box);
	Node goal_Man;
	if (manQue.size() == 1){
		manQue.pop();
		if (box.x == man.x&&box.y < man.y)
			director = 1;
		else if (box.x>man.x&&box.y == man.y)
			director = 2;
		else if (box.x == man.x&&box.y > man.y)
			director = 3;
		else if (box.x < man.x&&box.y == man.y)
			director = 4;
	}
	else{
		manQue.pop();
		goal_Man = manQue.front();
		if (goal_Man.x == man.x&&goal_Man.y < man.y)
			director = 1;
		else if (goal_Man.x>man.x&&goal_Man.y == man.y)
			director = 2;
		else if (goal_Man.x = man.x&&goal_Man.y > man.y)
			director = 3;
		else if (goal_Man.x < man.x&&goal_Man.y == man.y)
			director = 4;
	};
	changeDirect(director);
	director = 0;
	for (int i = 0; i < mapW; i++)
	{
		delete[]manParent[i];
		delete[]boxParent[i];
	}
	delete[]manParent;
	delete[]boxParent;

	return true;
}

PushBox::~PushBox()
{
	for (int i = 0; i < mapW; i++)
		delete[]isRood[i];
	delete[]isRood;
}