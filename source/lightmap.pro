QT       += core gui widgets webenginewidgets

TARGET = lightmap
TEMPLATE = app
CONFIG += console

include (def.pri)

SOURCES += 	source/main.cpp \
			source/lightmapwidget.cpp \
			source/bridge.cpp 
			

HEADERS  += include/lightmapwidget.h \
			include/bridge.h 

FORMS    += ui/lightmapwidget.ui  

INCLUDEPATH	+= ./include 
	
TRANSLATIONS = lang/lightmap_zh.ts

