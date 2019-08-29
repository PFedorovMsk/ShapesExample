#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "shape.h"
#include <QPointF>


// четырехугольник (почти как полигон, но не полигон :Р)
class Quadrilateral : public Shape
{
public:
    Quadrilateral();
    Quadrilateral(const QColor &bodyColor, const QColor &borderColor, double borderWidth = 1.0,
                  const QVector<QPointF> &vertices = {{-10.0, -10.0}, {-10.0, 10.0}, {10.0, 10.0}, {10.0, -10.0}});

    ~Quadrilateral() override = default;

    Quadrilateral(const Quadrilateral &) = default;
    Quadrilateral(Quadrilateral &&)      = default;

    Quadrilateral &operator=(const Quadrilateral &) = default;
    Quadrilateral &operator=(Quadrilateral &&) = default;

    const QVector<QPointF> &vertices() const;

    void setVertices(const QVector<QPointF> &vertices);

    void draw(QPainter *painter) const override;

private:
    QVector<QPointF> m_vertices;
};


#endif // QUADRILATERAL_H
