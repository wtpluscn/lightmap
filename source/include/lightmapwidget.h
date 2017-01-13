#ifndef LIGHT_MAP_WIDGET_H
#define LIGHT_MAP_WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class LightMapWidget;
}

class LightMapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LightMapWidget(QWidget *parent = 0);
    ~LightMapWidget();

private slots:    
    void onBtnLightOn();
    void onBtnLightOff();
	void onBtnAddLight();
	void onTimeOut();
private:
	QTimer m_timer;
    Ui::LightMapWidget *ui;
    void InitForm();
};

#endif // LIGHT_MAP_WIDGET_H
