/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2014 Piotr Wójcik <chocimier@tlen.pl>
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

#ifndef OTTER_OPERABOOKMARKSIMPORTER_H
#define OTTER_OPERABOOKMARKSIMPORTER_H

#include "../../../core/BookmarksImporter.h"
#include "../../../ui/BookmarksImporterWidget.h"

#include <QtCore/QFile>

namespace Otter
{

enum OperaBookmarkEntry
{
	NoOperaBookmarkEntry = 0,
	UrlOperaBookmarkEntry = 1,
	FolderOperaBookmarkEntry = 2,
	FolderEndOperaBookmarkEntry = 3,
	SeparatorOperaBookmarkEntry = 4
};

class OperaBookmarksImporter : public BookmarksImporter
{
	Q_OBJECT

public:
	explicit OperaBookmarksImporter(QObject *parent = NULL);
	~OperaBookmarksImporter();

	QWidget* getOptionsWidget();
	QString getTitle() const;
	QString getDescription() const;
	QString getVersion() const;
	QString getSuggestedPath() const;
	QString getBrowser() const;

public slots:
	bool setPath(const QString &path, bool isPrefix = false);
	bool import();

protected:
	void handleOptions();

private:
	QFile *m_file;
	BookmarksImporterWidget *m_optionsWidget;
	bool m_duplicate;
};

}

#endif