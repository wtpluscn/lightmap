#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>
#include <QJSValue>
#include <functional>
#include <QVariant>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantList>


typedef struct
{
	QString strName;
	QString strDesc;
	float   fLng;
	float	fLat;
	int		nValue;
}Light_t;

class bridge : QObject
{
Q_OBJECT
public:
    static bridge* instance();
private:
    bridge();
	QList<Light_t> m_lightList;
	void SetLightValue(QString strName, int nValue);
signals:
    void sigUpdateLight();
	void sigLightStatus(const QString& strName, int nvalue);
public slots:
    void onLightOn(QString strName);
	void onLightOff(QString strName);
	void onUpdateData();
	QVariantList	GetLightData();
public:
	void			Init();
	Light_t			AddLight();
	const QList<Light_t>& GetLightList(){return m_lightList;}
};

#endif // BRIDGE_H
