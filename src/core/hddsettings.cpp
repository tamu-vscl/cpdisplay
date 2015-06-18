/* 
 * File:   hddsettings.cpp
 * Author: Madison Treat <madison.treat@tamu.edu>
 * 
 * Created on June 15, 2015, 6:39 PM
 */

#include "hddsettings.h"

#include <QCoreApplication>
#include <QSettings>
#include <QFile>
#include <QDir>

HDDSettings::HDDSettings(QString _filename, QObject* _parent)
: QObject(_parent)
{
   settings = NULL;
   m_userHomeDir = QDir::home().absolutePath();
   
   // Get config file from [application root directory]/config
   m_appRootDir = QCoreApplication::applicationDirPath();
   QDir appRoot(m_appRootDir);
   
   appRoot.cdUp();
   m_configDir = appRoot.absolutePath() + "/config";
   
   if (m_settingsFile == "") {
      m_settingsFile = m_configDir + "/hdd-settings.ini";
   }
   
   if (!QFile::exists(m_settingsFile)) {
      qWarning() << "Warning: Settings file" << m_settingsFile << "does not exist. Exiting.";
      exit(1);
   }
   qDebug() << "Loading settings file:\n  " << m_settingsFile;
   
   loadSettingsFile(m_settingsFile);
   qDebug() << "   Done loading hdd settings.";
}

//HDDSettings::HDDSettings(const HDDSettings& orig)
//{
//}

HDDSettings::~HDDSettings()
{
}


void HDDSettings::loadSettingsFile(QString _filename)
{
   // If the settings pointer already exists, delete it to start fresh on a new
   // file, since this can potentially be called multiple times in an application.
   if (settings) {
      qDebug() << "Settings object already exists, re-creating it" << settings;
      delete settings;
   }
   settings = new QSettings(_filename, QSettings::IniFormat);
   
   // Load X-Plane 10 settings
   settings->beginGroup("xplane");
   m_xplanePort = settings->value("xplane_port").toInt();
   m_xplaneHost = QHostAddress(settings->value("xplane_host").toString());
   settings->endGroup(); // "xplane"
}
