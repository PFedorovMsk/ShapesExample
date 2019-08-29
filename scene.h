#ifndef SCENE_H
#define SCENE_H

#include "shape.h"
#include <QVector>
#include <QWidget>


class Scene : public QWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);
    ~Scene() override;

    void setBorderWidth(double value);
    void setRotationAngle(double value);
    void setScaleFactor(double value);

public slots:
    void addShape(Shape *shape);
    void clear();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    QVector<Shape *> m_shapes;
};


#endif // SCENE_H
