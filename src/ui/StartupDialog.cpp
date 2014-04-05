/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2013 - 2014 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#include "StartupDialog.h"
#include "../core/SessionsManager.h"

#include "ui_StartupDialog.h"

namespace Otter
{

StartupDialog::StartupDialog(QWidget *parent) : QDialog(parent),
	m_ui(new Ui::StartupDialog)
{
	m_ui->setupUi(this);

	const QStringList sessions = SessionsManager::getSessions();
	QMultiHash<QString, SessionInformation> information;

	for (int i = 0; i < sessions.count(); ++i)
	{
		const SessionInformation session = SessionsManager::getSession(sessions.at(i));

		information.insert((session.title.isEmpty() ? tr("(Untitled)") : session.title), session);
	}

	const QList<SessionInformation> sorted = information.values();

	for (int i = 0; i < sorted.count(); ++i)
	{
		m_ui->sessionComboBox->addItem((sorted.at(i).title.isEmpty() ? tr("(Untitled)") : sorted.at(i).title), sorted.at(i).path);
	}
}

StartupDialog::~StartupDialog()
{
	delete m_ui;
}

}