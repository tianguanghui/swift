/*
 * Copyright (c) 2010 Kevin Smith
 * Licensed under the GNU General Public License v3.
 * See Documentation/Licenses/GPLv3.txt for more information.
 */

#include "Swift/QtUI/QtAboutWidget.h"

#include <QCoreApplication>
#include <QIcon>
#include <QLabel>
#include <QVBoxLayout>
#include <QtGlobal>


#include "Swiften/Application/Application.h"

namespace Swift {

QtAboutWidget::QtAboutWidget() : QDialog() {
	resize(180, 240);
	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->setAlignment(Qt::AlignHCenter);
	setLayout(mainLayout);
	
	QLabel* iconLabel = new QLabel(this);
	iconLabel->setPixmap(QIcon(":/logo-shaded-text.256.png").pixmap(90, 90));
	iconLabel->setAlignment(Qt::AlignHCenter);
	mainLayout->addWidget(iconLabel);
	
	QLabel* appNameLabel = new QLabel("<center><font size='+1'><b>" + QCoreApplication::applicationName() + "</b></font></center>", this);
	mainLayout->addWidget(appNameLabel);
	
	QLabel* versionLabel = new QLabel(QString("<center><font size='-1'>Version ") + QCoreApplication::applicationVersion() + "</font></center>", this);
	mainLayout->addWidget(versionLabel);
	QString buildString = QString("<center><font size='-1'>Built with: Qt version ") + QT_VERSION_STR;
	buildString += QString("<br/>Running with Qt version ") + qVersion();
	buildString += "</font></center>";
	QLabel* buildLabel = new QLabel(buildString, this);
	mainLayout->addWidget(buildLabel);

	setFixedSize(minimumSizeHint());
}

}
