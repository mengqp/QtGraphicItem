######################################################################
# Automatically generated by qmake (2.01a) Tue Sep 25 14:33:06 2018
######################################################################

TEMPLATE = app
TARGET = GraphicsItemDev
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += GraphicsItemBF.hpp GraphicsItemBN.hpp GraphicsItemDev.hpp Widget.h
SOURCES += GraphicsItemBF.cpp \
           GraphicsItemBN.cpp \
           GraphicsItemDev.cpp \
           main.cpp \
           Widget.cpp
TARGET=./Debug/GraphicsItemDev
CONFIG+=Debug
OBJECTS_DIR = ./build/obj/
MOC_DIR = build/moc/
UI_DIR=build/ui
QT += gui core sql xml
