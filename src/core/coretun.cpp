/*
    Copyright (C) 2015 by Johannes Schwab <mail@jschwab.org>
    Copyright © 2015 by The qTox Project

    This file is part of qTox, a Qt-based graphical interface for Tox.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "core.h"
#include <QDebug>

void Core::tunCallback(ToxTun::Event event, uint32_t friendId, void* coreVoid) {
    Core *core = static_cast<Core*>(coreVoid);

    switch(event) {
        case ToxTun::Event::ConnectionRequested:
            emit core->tunRequested(friendId);
            break;
        case ToxTun::Event::ConnectionAccepted:
            emit core->tunAccepted(friendId);
            break;
        case ToxTun::Event::ConnectionRejected:
        case ToxTun::Event::ConnectionClosed:
            emit core->tunClosed(friendId);
            break;
        default:
            qWarning() << "Recieved unhandled event from ToxTun";
    }
}

void Core::startTun(uint32_t friendId)
{
    if (!toxtun) return;
    toxtun->sendConnectionRequest(friendId);
    qDebug() << QString("Requesting tun connection to %1").arg(friendId);
}

void Core::acceptTun(uint32_t friendId)
{
    if (!toxtun) return;
    toxtun->acceptConnection(friendId);
    qDebug() << QString("Accpeted connection from %1").arg(friendId);
}

void Core::closeTun(uint32_t friendId)
{
    if (!toxtun) return;
    toxtun->closeConnection();
    qDebug() << QString("Closing connection to %1").arg(friendId);
}

void Core::rejectTun(uint32_t friendId)
{
    if (!toxtun) return;
    toxtun->rejectConnection(friendId);
    qDebug() << QString("Rejecting connection to %1").arg(friendId);
}
