#include "shape.h"
#include <cmath>


Shape::Shape()
    : m_bodyColor(Qt::red)
    , m_borderColor(Qt::black)
    , m_borderWidth(1.0)
    , m_visible(true)
    , m_rotationAngle(0.0)
    , m_scaleFactor(1.0)
{
}

Shape::Shape(const QColor &bodyColor, const QColor &borderColor, double borderWidth)
    : m_bodyColor(bodyColor)
    , m_borderColor(borderColor)
    , m_borderWidth(borderWidth)
    , m_visible(true)
    , m_rotationAngle(0.0)
    , m_scaleFactor(1.0)
{
    if (m_borderWidth <= 0) {
        m_borderWidth = 1.0;
    }
}

const QColor &Shape::bodyColor() const
{
    return m_bodyColor;
}

const QColor &Shape::borderColor() const
{
    return m_borderColor;
}

double Shape::borderWidth() const
{
    return m_borderWidth;
}

bool Shape::isVisible() const
{
    return m_visible;
}

double Shape::rotationAngle() const
{
    return m_rotationAngle;
}

double Shape::scaleFactor() const
{
    return m_scaleFactor;
}

void Shape::setBodyColor(const QColor &color)
{
    m_bodyColor = color;
}

void Shape::setBorderColor(const QColor &color)
{
    m_borderColor = color;
}

void Shape::setBorderWidth(double widht)
{
    if (widht <= 0) {
        return;
    }
    m_borderWidth = widht;
}

void Shape::setVisible(bool value)
{
    m_visible = value;
}

void Shape::setRotationAngle(double value)
{
    double z = value > 0.0 ? 1.0 : -1.0;
    value    = std::fabs(value);
    while (value >= 360.0) {
        value -= 360.0;
    }

    m_rotationAngle = z * value;
}

void Shape::setScaleFactor(double value)
{
    if (value <= 0) {
        return;
    }
    m_scaleFactor = value;
}
