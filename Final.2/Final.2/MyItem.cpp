#include "MyItem.h"

MyItem::MyItem()
{
	photo=new QPixmap("map.jpg");
}

QRectF MyItem::boundingRect()const
{
	return photo->rect();
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *poption, QWidget *widget)
{
	painter->translate(-4750, -3500);
	painter->drawPixmap(photo->rect(), *photo);
	update();
}

MyItem::~MyItem()
{

}