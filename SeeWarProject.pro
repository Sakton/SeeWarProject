QT += quick

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
	CppModule/GameCore/emptycell.cpp \
	CppModule/GameCore/flot.cpp \
	CppModule/GameCore/modelflot.cpp \
	CppModule/GameCore/paluba.cpp \
	CppModule/GameCore/ship.cpp \
	CppModule/Model/abstractfield.cpp \
	CppModule/Model/abstractfieldelement.cpp \
	CppModule/Model/abstractflot.cpp \
	CppModule/Model/abstractgamefigure.cpp \
	CppModule/Model/arragementmodel.cpp \
	CppModule/Model/field.cpp \
	CppModule/Model/fieldelement.cpp \
	QmlModule/cpp/guiloader.cpp \
	main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#TODO тут плохо!!!
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
	ShemeAndOter/bigstructure.qmodel \
	ShemeAndOter/model1.qmodel \
	ShemeAndOter/networkmodel.qmodel \
	ShemeAndOter/old.7z \
	ShemeAndOter/qmlloadermodel.qmodel \
	ShemeAndOter/shipmodel.qmodel \
	ShemeAndOter/useCase \
	android/AndroidManifest.xml \
	android/build.gradle \
	android/gradle/wrapper/gradle-wrapper.jar \
	android/gradle/wrapper/gradle-wrapper.properties \
	android/gradlew \
	android/gradlew.bat \
	android/res/values/libs.xml \
	trrttr

HEADERS += \
	CppModule/GameCore/emptycell.h \
	CppModule/GameCore/flot.h \
	CppModule/GameCore/modelflot.h \
	CppModule/GameCore/paluba.h \
	CppModule/GameCore/ship.h \
	CppModule/Model/abstractfield.h \
	CppModule/Model/abstractfieldelement.h \
	CppModule/Model/abstractflot.h \
	CppModule/Model/abstractgamefigure.h \
	CppModule/Model/arragementmodel.h \
	CppModule/Model/config.h \
	CppModule/Model/field.h \
	CppModule/Model/fieldelement.h \
	QmlModule/cpp/guiloader.h

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
	ANDROID_PACKAGE_SOURCE_DIR = \
		$$PWD/android
}
