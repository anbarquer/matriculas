FORMS += mainForm.ui 
 
HEADERS += pracaoc.h \
           imageprocess.h 
           
SOURCES += pracaoc.cpp \
           main.cpp \
           imageprocess.cpp 
           
TEMPLATE = app

CONFIG += release \
warn_on \
thread \
qt

QMAKE_CXXFLAGS  += -m32
QMAKE_CFLAGS  += -m32
QMAKE_LFLAGS  += -m32
QMAKE_LIBDIR  += /usr/lib32

TARGET = ../bin/pracaoc

