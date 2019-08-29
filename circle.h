#ifndef Circle_H
#define Circle_H

#include "shape.h"
#include <QPointF>


class Circle : public Shape
{
public:
    Circle();
    Circle(const QColor &bodyColor, const QColor &borderColor, double borderWidth = 1.0,
           const QPointF &center = QPointF(0, 0), double radius = 10.0);

    ~Circle() override = default;

    Circle(const Circle &) = default;
    Circle(Circle &&)      = default;

    Circle &operator=(const Circle &) = default;
    Circle &operator=(Circle &&) = default;

    double radius() const;
    const QPointF &center() const;

    void setRadius(double value);
    void setCenter(const QPointF &center);

    void draw(QPainter *painter) const override;

private:
    QPointF m_center;
    double  m_radius;
};


#endif // Circle_H
