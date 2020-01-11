TEMPLATE = app
INCLUDEPATH += .

HEADERS     = bookdelegate.h bookwindow.h initdb.h \
    login.h
RESOURCES   = books.qrc
SOURCES     = bookdelegate.cpp main.cpp bookwindow.cpp \
    login.cpp
FORMS       = bookwindow.ui \
    login.ui

QT += sql widgets widgets
requires(qtConfig(tableview))

target.path = $$[QT_INSTALL_EXAMPLES]/sql/books
INSTALLS += target
