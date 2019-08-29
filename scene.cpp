#include "scene.h"

#include "circle.h"

Scene::Scene(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

Scene::~Scene()
{
    for (auto shape : m_shapes) {
        delete shape;
    }
}


void Scene::addShape(Shape *shape)
{
    if (shape == nullptr) {
        return;
    }

    m_shapes.append(shape);
    emit update();
}

void Scene::clear()
{
    for (auto shape : m_shapes) {
        delete shape;
    }
    m_shapes.clear();

    emit update();
}

void Scene::setBorderWidth(double value)
{
    for (auto shape : m_shapes) {
        shape->setBorderWidth(value);
    }
}

void Scene::setRotationAngle(double value)
{
    for (auto shape : m_shapes) {
        shape->setRotationAngle(value);
    }
}

void Scene::setScaleFactor(double value)
{
    for (auto shape : m_shapes) {
        shape->setScaleFactor(value);
    }
}

void Scene::paintEvent(QPaintEvent *)
{
    if (m_shapes.count() == 0) {
        return;
    }

    QPainter *painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing, true);

    for (auto shape : m_shapes) {
        painter->save();
        shape->draw(painter);
        painter->restore();
    }
}
