#include "lightmapwidget.h"
#include "ui_lightmapwidget.h"
#include "bridge.h"
#include <QWebChannel>

#define bridgeins bridge::instance()

LightMapWidget::LightMapWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::LightMapWidget)
{
	ui->setupUi(this);
	InitForm();
	connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(onBtnAddLight()));
	connect(ui->btnLightOn, SIGNAL(clicked()), this, SLOT(onBtnLightOn()));
	connect(ui->btnLightOff, SIGNAL(clicked()), this, SLOT(onBtnLightOff()));
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
	m_timer.start(1000);
}

LightMapWidget::~LightMapWidget()
{
	delete ui;
}

void LightMapWidget::InitForm()
{	
    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject("bridge", (QObject*)bridgeins);
    ui->webView->page()->setWebChannel(channel);	
	ui->webView->page()->load(QUrl(qApp->applicationDirPath() + "/index.html"));
	
	bridgeins->Init();
	
	const QList<Light_t>& list = bridgeins->GetLightList();
	int nCount = list.count();	
	for(int i=0; i<nCount; i++)
	{
		Light_t tLight = list[i];
		ui->cbLight->addItem(tLight.strDesc, tLight.strName);
	}
	ui->cbLight->setCurrentIndex(0);
	
	
	this->showMaximized();
}

void LightMapWidget::onBtnAddLight()
{
	Light_t tLight = bridgeins->AddLight();
	ui->cbLight->addItem(tLight.strDesc, tLight.strName);
	ui->cbLight->setCurrentIndex(ui->cbLight->count()-1);
	bridgeins->onUpdateData();
}

void LightMapWidget::onBtnLightOn()
{
	QString strName = ui->cbLight->currentData().toString();
	bridgeins->onLightOn(strName);
}

void LightMapWidget::onBtnLightOff()
{
	QString strName = ui->cbLight->currentData().toString();
	bridgeins->onLightOff(strName);
}

void LightMapWidget::onTimeOut()
{
//	bridgeins->onUpdateStatus();
}
