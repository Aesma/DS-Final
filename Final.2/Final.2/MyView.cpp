#include "MyView.h"

MyView::MyView(QWidget *parent)
:QGraphicsView(parent),
m_scale(1.0),
m_zoomDelta(0.1),
m_translateSpeed(1.0),
m_translateButton(Qt::LeftButton),
m_bMouseTranslate(false)
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setCursor(Qt::PointingHandCursor);
	setRenderHint(QPainter::Antialiasing);

	setSceneRect(INT_MIN / 2, INT_MIN / 2, INT_MAX, INT_MAX);
	centerOn(0, 0);
}

void MyView::setSTranslateSpeed(qreal speed)
{
	Q_ASSERT_X(speed >= 0.0 && speed <= 2.0,
		"InteractiveView::setTranslateSpeed", "Speed should be in range [0.0, 2.0].");
	m_translateSpeed = speed;
}

qreal MyView::translateSpeed() const
{
	return m_translateSpeed;
}

void MyView::setZoomDelta(qreal delta)
{
	Q_ASSERT_X(delta >= 0.0 && delta <= 1.0,
		"InteractiveView::setZoomDelta", "Delta should be in range [0.0, 1.0].");
	m_zoomDelta = delta;
}

void MyView::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bMouseTranslate){
		QPointF mouseDelta = mapToScene(event->pos()) - mapToScene(m_lastMousePos);
		translate(mouseDelta);
	}

	m_lastMousePos = event->pos();

	QGraphicsView::mouseMoveEvent(event);
}

void MyView::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == m_translateButton) {
		QPointF point = mapToScene(event->pos());
			m_bMouseTranslate = true;
			m_lastMousePos = event->pos();
	}

	QGraphicsView::mousePressEvent(event);
}

void MyView::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == m_translateButton)
		m_bMouseTranslate = false;

	QGraphicsView::mouseReleaseEvent(event);
}

void MyView::wheelEvent(QWheelEvent *event)
{
	// ���ֵĹ�����
	QPoint scrollAmount = event->angleDelta();
	// ��ֵ��ʾ����Զ��ʹ���ߣ��Ŵ󣩣���ֵ��ʾ����ʹ���ߣ���С��
	scrollAmount.y() > 0 ? zoomIn() : zoomOut();
}

void MyView::zoomIn()
{
	zoom(1 + m_zoomDelta);
}

void MyView::zoomOut()
{
	zoom(1 - m_zoomDelta);
}

void MyView::zoom(float scaleFactor)
{
	// ��ֹ��С�����
	qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
	if (factor < 0.07 || factor > 100)
		return;

	scale(scaleFactor, scaleFactor);
	m_scale *= scaleFactor;
}

void MyView::translate(QPointF delta)
{
	// ���ݵ�ǰ zoom ����ƽ����
	delta *= m_scale;
	delta *= m_translateSpeed;

	// view ��������µĵ���Ϊê������λ scene
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	QPoint newCenter(width() / 2 - delta.x(), height() / 2 - delta.y());
	centerOn(mapToScene(newCenter));

	// scene �� view �����ĵ���Ϊê��
	setTransformationAnchor(QGraphicsView::AnchorViewCenter);
}

MyView::~MyView()
{

}