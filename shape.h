#ifndef SHAPE_H
#define SHAPE_H

#include <QColor>
#include <QPainter>


class Shape
{
public:
    Shape();
    Shape(const QColor &bodyColor, const QColor &borderColor, double borderWidth = 1.0);

    virtual ~Shape() = default;

    Shape(const Shape &) = default;
    Shape(Shape &&)      = default;

    Shape &operator=(const Shape &) = default;
    Shape &operator=(Shape &&) = default;

    const QColor &bodyColor() const;
    const QColor &borderColor() const;
    double        borderWidth() const;
    bool          isVisible() const;
    double        rotationAngle() const;
    double        scaleFactor() const;

    void setBodyColor(const QColor &color);
    void setBorderColor(const QColor &color);
    void setBorderWidth(double widht);
    void setVisible(bool value);
    void setRotationAngle(double value);
    void setScaleFactor(double value);

    virtual void draw(QPainter *) const = 0;

private:
    QColor m_bodyColor;
    QColor m_borderColor;
    double m_borderWidth;
    bool   m_visible;
    double m_rotationAngle;
    double m_scaleFactor;
};


#endif // SHAPE_H
