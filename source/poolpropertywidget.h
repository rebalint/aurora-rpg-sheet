#ifndef POOLPROPERTYWIDGET_H
#define POOLPROPERTYWIDGET_H

#include <QWidget>
#include "scorepropertywidget.h"
#include "poolproperty.h"

namespace Ui {
class PoolPropertyWidget;
}

class PoolPropertyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PoolPropertyWidget(QWidget *parent = nullptr);
    ~PoolPropertyWidget();

    void poolConnect(PoolProperty * poolProp);  //setup

private:
    Ui::PoolPropertyWidget *ui;

signals:
    void manualCurrentChange(int newCurrent);

public slots:
    void maxChange(int newMax);
};

#endif // POOLPROPERTYWIDGET_H
