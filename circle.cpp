#include "Circle.h"


Circle::Circle()
    : Shape()
    , m_center(QPointF(0.0, 0.0))
    , m_radius(10.0)
{
}

Circle::Circle(const QColor &bodyColor, const QColor &borderColor, double borderWidth, const QPointF &center,
               double radius)
    : Shape(bodyColor, borderColor, borderWidth)
    , m_center(center)
    , m_radius(radius)
{
    if (m_radius <= 0) {
        m_radius = 1.0;
    }
}

double Circle::radius() const
{
    return m_radius;
}

const QPointF &Circle::center() const
{
    return m_center;
}

void Circle::setRadius(double value)
{
    if (value <= 0) {
        return;
    }
    m_radius = value;
}

void Circle::setCenter(const QPointF &center)
{
    m_center = center;
}

void Circle::draw(QPainter *painter) const
{
    if (!isVisible()) {
        return;
    }

    painter->setBrush(QBrush(bodyColor()));
    painter->setPen(QPen(borderColor(), borderWidth()));
    // painter->rotate(this->rotationAngle());
    painter->scale(this->scaleFactor(), this->scaleFactor());
    painter->drawEllipse(m_center, m_radius, m_radius);
}
