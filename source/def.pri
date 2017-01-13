PRJ_HOME = $$PWD/..
message($$PWD)
message($${PRJ_HOME})
contains(CONFIG, debug) {
	BUILDDIR        = $${PRJ_HOME}/Debug/
}
contains(CONFIG, release) {
	BUILDDIR        = $${PRJ_HOME}/Release/
}
message($${BUILDDIR})

win32:BUILDDIR  = $$join(BUILDDIR,,,win32)
unix:BUILDDIR   = $$join(BUILDDIR,,,unix)
macx:BUILDDIR   = $$join(BUILDDIR,,,macx)
BUILDDIR        = $$join(BUILDDIR,,,/$$TARGET)

UI_DIR          = .
contains(TEMPLATE, app) {
	UI_DIR          = $${BUILDDIR}/ui
}

UIC_DIR         = $${BUILDDIR}/uic
MOC_DIR         = $${BUILDDIR}/moc
RCC_DIR         = $${BUILDDIR}/rcc
OBJECTS_DIR     = $${BUILDDIR}/obj

contains(TEMPLATE, lib) {
    CONFIG  += dll
    unix:DESTDIR  = $${PRJ_HOME}/bin 
    win32:DESTDIR  = $${PRJ_HOME}/lib 
    win32:DLLDESTDIR = $${PRJ_HOME}/bin    
}
contains(TEMPLATE, app) {
	DESTDIR		= $${PRJ_HOME}/bin  
}

INCLUDEPATH += include $${PRJ_HOME}/source/include

win32 {
LIBPATH += $${PRJ_HOME}/lib
DEFINES += WIN32 _WINDOWS _AFXDLL 
DEFINES -= _USRDLL
}

unix {
LIBPATH += $${PRJ_HOME}/bin
}

