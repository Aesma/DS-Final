#ifndef MYITEM_H
#define MYITEM_H

#include "QtHead.h"

class MyItem:public QGraphicsItem
{
public:
	MyItem();
	~MyItem();
protected:
	QRectF boundingRect()const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *poption, QWidget *widget);
private:
	QPixmap *photo;
};

#endif