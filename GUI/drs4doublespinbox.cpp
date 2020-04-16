/****************************************************************************
**
**  DDRS4PALS, a software for the acquisition of lifetime spectra using the
**  DRS4 evaluation board of PSI: https://www.psi.ch/drs/evaluation-board
**
**  Copyright (C) 2016-2020 Danny Petschke
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see http://www.gnu.org/licenses/.
**
*****************************************************************************
**
**  @author: Danny Petschke
**  @contact: danny.petschke@uni-wuerzburg.de
**
*****************************************************************************/

#include "drs4doublespinbox.h"

DRS4DoubleSpinBox::DRS4DoubleSpinBox(QWidget *parent) :
    QDoubleSpinBox(parent) {}

DRS4DoubleSpinBox::~DRS4DoubleSpinBox() {}

bool DRS4DoubleSpinBox::event(QEvent *event)
{
    switch(event->type()) {
    case QEvent::Type::HoverEnter:
    case QEvent::Type::HoverMove:
    case QEvent::Type::MouseButtonPress:
    case QEvent::Type::MouseButtonRelease:
    case QEvent::Type::KeyPress:
    case QEvent::Type::KeyRelease:
    case QEvent::Type::CursorChange:
    case QEvent::Type::FocusIn: {
        if (!QToolTip::isVisible())
            QToolTip::showText(mapToGlobal(QPoint(0, -height())), "<nobr><font color=\"red\">Warning: Performing this action will reset the spectra!</font></nobr>", this, QRect(), 25000);
        break;
    }

    case QEvent::Type::HoverLeave:
    case QEvent::Type::Leave:
    case QEvent::Type::FocusOut:
        if (QToolTip::isVisible())
            QToolTip::hideText();
        break;
    }

    return QDoubleSpinBox::event(event);
}
