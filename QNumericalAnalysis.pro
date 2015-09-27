#-------------------------------------------------
#
# Project created by QtCreator 2015-09-26T20:03:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = QNumericalAnalysis
TEMPLATE = app

CONFIG(debug, debug|release) {
  TARGET = $$join(TARGET,,,d) # if compiling in debug mode, append a "d" to the library name
  QMAKE_TARGET_PRODUCT = "QCustomPlot (debug mode)"
  QMAKE_TARGET_DESCRIPTION = "Plotting library for Qt (debug mode)"
} else {
  QMAKE_TARGET_PRODUCT = "QCustomPlot"
  QMAKE_TARGET_DESCRIPTION = "Plotting library for Qt"
}
QMAKE_TARGET_COMPANY = "www.qcustomplot.com"
QMAKE_TARGET_COPYRIGHT = "Copyright (C) by Emanuel Eichhammer"



FORMS    += numericalmainwindow.ui \
    bisectiongui.ui

HEADERS += \
    lepton/CompiledExpression.h \
    lepton/CustomFunction.h \
    lepton/Exception.h \
    lepton/ExpressionProgram.h \
    lepton/ExpressionTreeNode.h \
    lepton/Operation.h \
    lepton/ParsedExpression.h \
    lepton/Parser.h \
    lepton/windowsIncludes.h \
    Lepton.h \
    MSVC_erfc.h \
    numericalmainwindow.h \
    qcustomplot.h \
    qparser.h \
    bisectionmethod.h \
    bisectiongui.h

SOURCES += \
    CompiledExpression.cpp \
    ExpressionProgram.cpp \
    ExpressionTreeNode.cpp \
    main.cpp \
    numericalmainwindow.cpp \
    Operation.cpp \
    ParsedExpression.cpp \
    Parser.cpp \
    qcustomplot.cpp \
    qparser.cpp \
    bisectionmethod.cpp \
    bisectiongui.cpp

