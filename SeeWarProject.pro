QT += quick network

CONFIG += c++1z
CONFIG += resources_big

VERSION = 1.0
QMAKE_TARGET_COMPANY = Razumov_Roman
QMAKE_TARGET_PRODUCT = SeeWar
QMAKE_TARGET_DESCRIPTION = SeeWar
QMAKE_TARGET_COPYRIGHT = Razumov_Roman

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
	CppModule/Elements/abstractgamefigure.cpp \
	CppModule/Elements/damageemptycell.cpp \
	CppModule/Elements/damageshipcell.cpp \
	CppModule/Elements/emptycell.cpp \
	CppModule/Elements/forbiddencell.cpp \
	CppModule/Elements/paluba.cpp \
	CppModule/Field/abstractfieldelement.cpp \
	CppModule/Field/fieldelement.cpp \
	CppModule/Figure/framing.cpp \
	CppModule/Figure/ship.cpp \
	CppModule/Model/field.cpp \
	CppModule/Model/flot.cpp \
	CppModule/User/baseuser.cpp \
	CppModule/User/enemyuser.cpp \
	CppModule/User/ownuser.cpp \
	CppModule/gameblackwater.cpp \
	NetModule/gametcpclient.cpp \
	NetModule/myjsonobjects.cpp \
	QmlModule/cpp/guiloader.cpp \
	main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD/QmlModule/qml/DefaultGui/

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
	QmlModule/qml/DefaultGui/Settings/Settings.qml \
	QmlModule/qml/DefaultGui/Settings/qmldir \
	QmlModule/qml/DefaultGui/img/1x.png \
	QmlModule/qml/DefaultGui/img/2x.png \
	QmlModule/qml/DefaultGui/img/3x.png \
	QmlModule/qml/DefaultGui/img/4x.png \
	QmlModule/qml/DefaultGui/qmldir \
	ShemeAndOter/NetWork \
	ShemeAndOter/shemeapplication.qmodel \
	ShemeAndOter/useCase \
	android/AndroidManifest.xml \
	android/build.gradle \
	android/gradle/wrapper/gradle-wrapper.jar \
	android/gradle/wrapper/gradle-wrapper.properties \
	android/gradlew \
	android/gradlew.bat \
	android/res/values/libs.xml \
	plan \
	protocolToExchangeServer \
	trrttr

HEADERS += \
	CppModule/Elements/abstractgamefigure.h \
	CppModule/Elements/damageemptycell.h \
	CppModule/Elements/damageshipcell.h \
	CppModule/Elements/emptycell.h \
	CppModule/Elements/forbiddencell.h \
	CppModule/Elements/paluba.h \
	CppModule/Field/abstractfieldelement.h \
	CppModule/Field/fieldelement.h \
	CppModule/Figure/framing.h \
	CppModule/Figure/ship.h \
	CppModule/Model/config.h \
	CppModule/Model/field.h \
	CppModule/Model/flot.h \
	CppModule/User/baseuser.h \
	CppModule/User/enemyuser.h \
	CppModule/User/ownuser.h \
	CppModule/gameblackwater.h \
	NetModule/gametcpclient.h \
	NetModule/myjsonobjects.h \
	QmlModule/cpp/guiloader.h

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
	ANDROID_PACKAGE_SOURCE_DIR = \
		$$PWD/android
}
