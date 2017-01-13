#include "bridge.h"
#include <QMessageBox>
#include <QJSEngine>
#include <QDebug>

bridge* bridge::instance()
{
    static bridge s_obj;
    return &s_obj;
}

bridge::bridge()
{
}

void bridge::Init()
{
	AddLight();
	AddLight();
}


Light_t	bridge::AddLight()
{
	static int s_count = 1;
	Light_t tLight;
	tLight.strName = QString("Light%1").arg(s_count);
	tLight.strDesc = QString("Light Description %1").arg(s_count);
	tLight.fLng = 121.0 + s_count*0.1;
	tLight.fLat = 37.3 + s_count*0.01;
	tLight.nValue = 0;
	m_lightList.append(tLight);	
	s_count++;
	return tLight;
}

QVariantList bridge::GetLightData()
{
	int nCount = m_lightList.count();
	QVariantList markerList;
	
	for(int i=0; i<nCount; i++)
	{
		Light_t tLight = m_lightList[i];
		QVariantMap map;
		map.insert("name", 	tLight.strName);
		map.insert("description", 	tLight.strDesc);
		map.insert("point", 	QString("%1,%2").arg(tLight.fLng).arg(tLight.fLat));	
		map.insert("value", 	tLight.nValue);
		markerList << map;
	}
	
	return markerList;
}


void bridge::onLightOn(QString strName)
{
	SetLightValue(strName, 1);
}

void bridge::onLightOff(QString strName)
{
	SetLightValue(strName, 0);
}

void bridge::SetLightValue(QString strName, int nValue)
{
	int nCount = m_lightList.count();	
	for(int i=0; i<nCount; i++)
	{
		Light_t tLight = m_lightList[i];
		if( m_lightList[i].strName == strName)
		{
			m_lightList[i].nValue = nValue;
			break;
		}
	}
	emit sigLightStatus(strName, nValue);
}

void bridge::onUpdateData()
{
	emit sigUpdateLight();
}

