/*
 * This file is part of TelepathyQt4
 *
 * Copyright (C) 2008-2009 Collabora Ltd. <http://www.collabora.co.uk/>
 * Copyright (C) 2008-2009 Nokia Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "debug.h"

/**
 * \defgroup debug Common debug support
 *
 * TelepathyQt4 has an internal mechanism for displaying debugging output. It
 * uses the Qt4 debugging subsystem, so if you want to redirect the messages,
 * use qInstallMsgHandler() from &lt;QtGlobal&gt;.
 *
 * Debugging output is divided into two categories: normal debug output and
 * warning messages. Normal debug output results in the normal operation of the
 * library, warning messages are output only when something goes wrong. Each
 * category can be invidually enabled.
 */

/**
 * \fn void enableDebug(bool enable)
 * \ingroup debug
 *
 * Enable or disable normal debug output from the library. If the library is not
 * compiled with debug support enabled, this has no effect; no output is
 * produced in any case.
 *
 * The default is <code>false</code> ie. no debug output.
 *
 * \param enable Whether debug output should be enabled or not.
 */

/**
 * \fn void enableWarnings(bool enable)
 * \ingroup debug
 *
 * Enable or disable warning output from the library. If the library is not
 * compiled with debug support enabled, this has no effect; no output is
 * produced in any case.
 *
 * The default is <code>true</code> ie. warning output enabled.
 *
 * \param enable Whether warnings should be enabled or not.
 */

#ifdef ENABLE_DEBUG

namespace
{
bool debugEnabled = false;
bool warningsEnabled = true;
}

void enableDebug(bool enable)
{
    debugEnabled = enable;
}

void enableWarnings(bool enable)
{
    warningsEnabled = enable;
}

bool isDebugEnabled()
{
    return debugEnabled;
}

bool isWarningsEnabled()
{
    return warningsEnabled;
}

Debug enabledDebug()
{
    if (debugEnabled) {
        return Debug(qDebug());
    } else {
        return Debug();
    }
}

Debug enabledWarning()
{
    if (warningsEnabled) {
        return Debug(qWarning());
    } else {
        return Debug();
    }
}

#else /* !defined(ENABLE_DEBUG) */

void enableDebug(bool enable)
{
    Q_UNUSED(enable);
}

void enableWarnings(bool enable)
{
    Q_UNUSED(enable);
}

bool isDebugEnabled()
{
    return false;
}

bool isWarningsEnabled()
{
    return false;
}

Debug enabledDebug()
{
    return Debug();
}

Debug enabledWarning()
{
    return Debug();
}

#endif /* !defined(ENABLE_DEBUG) */

