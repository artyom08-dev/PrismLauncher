// SPDX-License-Identifier: GPL-3.0-only
/*
 *  Prism Launcher - Minecraft Launcher
 *
 *  Palette and log colors taken from the Catppuccin Mocha theme by the
 *  Prism Launcher community:
 *  SPDX-FileCopyrightText: 2022 Catppuccin (MIT)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "CatppuccinMochaTheme.h"

#include <QColor>
#include <QObject>
#include <QPalette>

QString CatppuccinMochaTheme::id()
{
    return "Catppuccin-Mocha";
}

QString CatppuccinMochaTheme::name()
{
    return QObject::tr("Catppuccin Mocha");
}

QString CatppuccinMochaTheme::tooltip()
{
    return "";
}

QPalette CatppuccinMochaTheme::colorScheme()
{
    QPalette mochaPalette;
    mochaPalette.setColor(QPalette::Window, QColor(0x1e, 0x1e, 0x2e));
    mochaPalette.setColor(QPalette::WindowText, QColor(0xba, 0xc2, 0xde));
    mochaPalette.setColor(QPalette::Base, QColor(0x18, 0x18, 0x25));
    mochaPalette.setColor(QPalette::AlternateBase, QColor(0x1e, 0x1e, 0x2e));
    mochaPalette.setColor(QPalette::ToolTipBase, QColor(0xde, 0xe5, 0xfc));
    mochaPalette.setColor(QPalette::ToolTipText, QColor(0xde, 0xe5, 0xfc));
    mochaPalette.setColor(QPalette::Text, QColor(0xcd, 0xd6, 0xf4));
    mochaPalette.setColor(QPalette::Button, QColor(0x31, 0x32, 0x44));
    mochaPalette.setColor(QPalette::ButtonText, QColor(0xcd, 0xd6, 0xf4));
    mochaPalette.setColor(QPalette::BrightText, QColor(0xba, 0xc2, 0xde));
    mochaPalette.setColor(QPalette::Link, QColor(0xb4, 0xbe, 0xfe));
    mochaPalette.setColor(QPalette::Highlight, QColor(0xb4, 0xbe, 0xfe));
    mochaPalette.setColor(QPalette::HighlightedText, QColor(0x1e, 0x1e, 0x2e));
    mochaPalette.setColor(QPalette::PlaceholderText, QColor(0x6c, 0x70, 0x86));
    return fadeInactive(mochaPalette, fadeAmount(), fadeColor());
}

double CatppuccinMochaTheme::fadeAmount()
{
    return 0.5;
}

QColor CatppuccinMochaTheme::fadeColor()
{
    return QColor(0x6c, 0x70, 0x86);
}

bool CatppuccinMochaTheme::hasStyleSheet()
{
    return true;
}

QString CatppuccinMochaTheme::appStyleSheet()
{
    return "QToolTip { color: #cdd6f4; background-color: #313244; border: 1px solid #313244 }";
}

LogColors CatppuccinMochaTheme::logColorScheme()
{
    auto colors = defaultLogColors(colorScheme());
    colors.foreground[MessageLevel::Launcher] = QColor(0xcb, 0xa6, 0xf7);
    colors.foreground[MessageLevel::Debug] = QColor(0xa6, 0xe3, 0xa1);
    colors.foreground[MessageLevel::Warning] = QColor(0xf9, 0xe2, 0xaf);
    colors.foreground[MessageLevel::Error] = QColor(0xf3, 0x8b, 0xa8);
    colors.foreground[MessageLevel::Fatal] = QColor(0x18, 0x18, 0x25);
    colors.background[MessageLevel::Fatal] = QColor(0xf3, 0x8b, 0xa8);
    return colors;
}
