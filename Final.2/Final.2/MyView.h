#ifndef MYVIEW_H
#define MYVIEW_H

#include "QtHead.h"

class MyView :public QGraphicsView
{
	Q_OBJECT
public:
	explicit MyView(QWidget *parent = 0);
	void setSTranslateSpeed(qreal speed);
	qreal translateSpeed()const;
	void setZoomDelta(qreal delta);
	qreal zoomDelta();
	~MyView();
protected:
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
public Q_SLOT:
	void zoomIn();  // �Ŵ�
	void zoomOut();  // ��С
	void zoom(float scaleFactor); // ���� - scaleFactor�����ŵı�������
	void translate(QPointF delta);  // ƽ��
private:
	Qt::MouseButton m_translateButton;
	qreal m_translateSpeed;  // ƽ���ٶ�
	qreal m_zoomDelta;  // ���ŵ�����
	bool m_bMouseTranslate;  // ƽ�Ʊ�ʶ
	QPoint m_lastMousePos;  // �������µ�λ��
	qreal m_scale;  // ����ֵ
};

#endif