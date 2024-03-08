#QT += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG+=c++11

##You can make your code fail to compile if it uses deprecated APIs.
##In order to do so, uncomment the following line.
##DEFINES += QT_DISABLE_DEPRECATED_BEFORE = \
#    0x060000 #disables all the APIs deprecated before Qt 6.0.0

#      SOURCES += main.cpp mainwindow.cpp

#                     HEADERS += mainwindow.h

#                                    FORMS += mainwindow
#                                                 .ui

##Default rules for deployment.
#                                                     qnx : target.path =
#          / tmp / $${TARGET} / bin else : unix : !android : target.path =
#              / opt / $${TARGET} /
#              bin !isEmpty(target.path) : INSTALLS += target

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    ../model/dijkstra_algorithm.c \
    ../model/token_stack.c \
    ../model/function_type_determinant.c \
    ../model/rpn_calculation.c \
    ../model/credits.c \
    mainwindow.cpp \
    qcustomplot.cpp \
    view/credit.cpp \
    view/deposite.cpp \
    view/plot.cpp


HEADERS += \
    mainwindow.h \
    ../headers/dijkstra_algorithm.h \
    ../headers/token_stack.h \
    ../headers/function_type_determinant.h \
    ../headers/rpn_calculation.h \
    ../headers/smart_calc.h \
    ../headers/credits.h \
    qcustomplot.h \
    view/credit.h \
    view/deposite.h \
    view/plot.h


FORMS += \
    mainwindow.ui \
    view/credit.ui \
    view/deposite.ui \
    view/plot.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

