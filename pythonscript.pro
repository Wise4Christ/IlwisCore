# Instructions:
#
# First build project "pythonapi" (follow the instructions in pythonapi.pro if not yet done)
# Then build project "pythonscript"

CONFIG += plugin
TARGET = pythonscript

include(global.pri)

DESTDIR = $$PWD/../libraries/$$PLATFORM$$CONF/extensions/$$TARGET
DLLDESTDIR = $$PWD/../output/$$PLATFORM$$CONF/bin/extensions/$$TARGET

TEMPLATE = lib

DEFINES += PYTHONSCRIPT_LIBRARY

resources.files += pythonscript/resources/libraries.config
resources.path = $$PWD/../output/$$PLATFORM$$CONF/bin/extensions/$$TARGET/resources

INSTALLS += resources

OTHER_FILES += \
    pythonscript/pythonscript.json

LIBS += -L$$PWD/../libraries/$$PLATFORM$$CONF -lilwiscore \
        -L$$PWD/../libraries/$$PLATFORM$$CONF/extensions/pythonapi -lpython35 \
        -L$$PWD/../libraries/$$PLATFORM$$CONF/extensions/pythonapi -l_ilwisobjects
		
win32:CONFIG(release, debug|release): {
    QMAKE_CXXFLAGS_RELEASE += -O2
}

INCLUDEPATH +=  $$PWD/core \
                $$PWD/../external/python35/include \
                $$PWD/../IlwisConnectors/pythonapi
DEPENDPATH +=   $$PWD/core \
                $$PWD/../external/python35/include

HEADERS += \
    pythonscript/pythonscriptmodule.h \
    pythonscript/runpython.h \
    pythonscript/pythonobjectfactory.h \
    pythonscript/pythonworkflowconnector.h \
    pythonscript/pythonscriptconnector.h \
    pythonscript/pythonscriptcatalogexplorer.h \
    pythonscript/callpythonoperation.h

SOURCES += \
    pythonscript/pythonscriptmodule.cpp \
    pythonscript/runpython.cpp \
    pythonscript/pythonobjectfactory.cpp \
    pythonscript/pythonworkflowconnector.cpp \
    pythonscript/pythonscriptconnector.cpp \
    pythonscript/pythonscriptcatalogexplorer.cpp \
    pythonscript/callpythonoperation.cpp




