#include "quadrilateral.h"


Quadrilateral::Quadrilateral()
    : Shape()
    , m_vertices({{-10.0, -10.0}, {-10.0, 10.0}, {10.0, 10.0}, {10.0, -10.0}})
{
}

Quadrilateral::Quadrilateral(const QColor &bodyColor, const QColor &borderColor, double borderWidth,
                             const QVector<QPointF> &vertices)
    : Shape(bodyColor, borderColor, borderWidth)
{
    setVertices(vertices);
}

const QVector<QPointF> &Quadrilateral::vertices() const
{
    return m_vertices;
}

void Quadrilateral::setVertices(const QVector<QPointF> &vertices)
{
    m_vertices = vertices;

    if (m_vertices.count() > 4) {
        m_vertices.resize(4);
    } else if (m_vertices.count() < 4) {
        m_vertices = {{-10.0, -10.0}, {-10.0, 10.0}, {10.0, 10.0}, {10.0, -10.0}};
    }
}

void Quadrilateral::draw(QPainter *painter) const
{
    if (!isVisible()) {
        return;
    }

    painter->setBrush(QBrush(bodyColor()));
    painter->setPen(QPen(borderColor(), borderWidth()));
    painter->rotate(this->rotationAngle());
    painter->scale(this->scaleFactor(), this->scaleFactor());

    QPolygonF polygon;
    for (auto point : m_vertices) {
        polygon.append(point);
    }

    painter->drawPolygon(polygon);
}
