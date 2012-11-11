QT      += xml
win32: CONFIG += console
HEADERS += \
    TNeuronLayer.h \
    TNeuron.h \
    TMultiLayerPerceptron.h \
    compressFunctions.h

SOURCES += \
    TNeuronLayer.cpp \
    TNeuron.cpp \
    TMultiLayerPerceptron.cpp \
    compressFunctions.cpp \
    main.cpp
