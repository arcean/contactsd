# This file is part of Contacts daemon
#
# Copyright (c) 2010-2011 Nokia Corporation and/or its subsidiary(-ies).
#
# Contact:  Nokia Corporation (info@qt.nokia.com)
#
# GNU Lesser General Public License Usage
# This file may be used under the terms of the GNU Lesser General Public License
# version 2.1 as published by the Free Software Foundation and appearing in the
# file LICENSE.LGPL included in the packaging of this file.  Please review the
# following information to ensure the GNU Lesser General Public License version
# 2.1 requirements will be met:
# http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
#
# In addition, as a special exception, Nokia gives you certain additional rights.
# These rights are described in the Nokia Qt LGPL Exception version 1.1, included
# in the file LGPL_EXCEPTION.txt in this package.
#
# Other Usage
# Alternatively, this file may be used in accordance with the terms and
# conditions contained in a signed written agreement between you and Nokia.

TEMPLATE = lib
QT -= gui
QT += dbus

CONFIG += plugin qtsparql qtcontacts_extensions_tracker cubi-0.1 cubi-0.1-tracker-0.10-ontologies
system(qdbusxml2cpp -c BuddyManagementAdaptor -a buddymanagementadaptor.h:buddymanagementadaptor.cpp com.nokia.contacts.buddymanagement.xml)

CONFIG(coverage):{
QMAKE_CXXFLAGS += -c -g  --coverage -ftest-coverage -fprofile-arcs
LIBS += -lgcov
}

CONFIG += link_pkgconfig
PKGCONFIG += TelepathyQt4 tracker-sparql-0.10
DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII

INCLUDEPATH += $$TOP_SOURCEDIR/src
DEFINES += ENABLE_DEBUG

HEADERS  = cdtpaccount.h \
    cdtpaccountcache.h \
    cdtpaccountcacheloader.h \
    cdtpaccountcachewriter.h \
    types.h \
    cdtpcontact.h \
    cdtpcontroller.h \
    cdtpplugin.h \
    cdtpquery.h \
    cdtpstorage.h \
    buddymanagementadaptor.h \
    cdtpavatarupdate.h

SOURCES  = cdtpaccount.cpp \
    cdtpaccountcacheloader.cpp \
    cdtpaccountcachewriter.cpp \
    cdtpcontact.cpp \
    cdtpcontroller.cpp \
    cdtpplugin.cpp \
    cdtpquery.cpp \
    cdtpstorage.cpp \
    buddymanagementadaptor.cpp \
    cdtpavatarupdate.cpp

TARGET = telepathyplugin
target.path = $$LIBDIR/contactsd-1.0/plugins

xml.files = com.nokia.contacts.buddymanagement.xml
xml.path = $$INCLUDEDIR/contactsd-1.0

INSTALLS += target xml

OTHER_FILES += \
    com.nokia.contacts.buddymanagement.xml
