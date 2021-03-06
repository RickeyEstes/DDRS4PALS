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

#ifndef DRS4PROGRAMSETTINGSMANAGER_H
#define DRS4PROGRAMSETTINGSMANAGER_H

#include <QMutex>
#include <QMutexLocker>

#include <QDateTime>

#include "dversion.h"

#include "DLib.h"

class DRS4ProgramSettingsManager
{
    DSimpleXMLNode *m_parentNode;

    DSimpleXMLNode *m_lastSaveDateNode;

    DSimpleXMLNode *m_renderPointsNode;

    DSimpleXMLNode *m_lastSimulationInputFilePathNode;
    DSimpleXMLNode *m_lastStreamInputFilePathNode;
    DSimpleXMLNode *m_lastStreamTextFileInputFilePathNode;
    DSimpleXMLNode *m_lastSettingsFilePathNode;
    DSimpleXMLNode *m_lastSaveDataFilePathNode;
    DSimpleXMLNode *m_lastSaveScriptFilePathNode;
    DSimpleXMLNode *m_lastSaveLogFilePathNode;
    DSimpleXMLNode *m_lastSaveTProfileFilePathNode;
    DSimpleXMLNode *m_lastPHSSaveFilePathNode;
    DSimpleXMLNode *m_lastRiseTimeDistrPathNode;
    DSimpleXMLNode *m_lastAreaDistrPathNode;

    DSimpleXMLNode *m_multicoreThreadingParentNode;
        DSimpleXMLNode *m_enableMulticoreThreadingNode;
        DSimpleXMLNode *m_pulsePairChunkSizeNode;

    mutable QMutex m_mutex;


    DRS4ProgramSettingsManager();
    virtual ~DRS4ProgramSettingsManager();

    bool save();
    bool load();

public:
    static DRS4ProgramSettingsManager *sharedInstance();

    void setSplineIntraPoints(int points);

    void setSimulationInputFilePath(const QString& path);
    void setStreamInputFilePath(const QString& path);
    void setStreamTextFileInputFilePath(const QString& path);
    void setSettingsFilePath(const QString& path);
    void setSaveDataFilePath(const QString& path);
    void setSaveScriptFilePath(const QString& path);
    void setSaveLogFilePath(const QString& path);
    void setSaveTProfilePath(const QString& path);
    void setSavePHSDataFilePath(const QString& path);
    void setSaveRiseTimeDistributionDataFilePath(const QString& path);
    void setSaveAreaDistributionDataFilePath(const QString& path);

    void setEnableMulticoreThreading(bool on);
    void setPulsePairChunkSize(int size);

    int splineIntraPoints();

    QString simulationInputFilePath();
    QString streamInputFilePath();
    QString streamTextFileInputFilePath();
    QString settingsFilePath();
    QString saveDataFilePath();
    QString saveScriptFilePath();
    QString saveLogFilePath();
    QString saveTProfileFilePath();
    QString savePHSDataFilePath();
    QString saveRiseTimeDistributionDataFilePath();
    QString saveAreaDistributionDataFilePath();

    bool isMulticoreThreadingEnabled();
    int pulsePairChunkSize();

    void showXMLContent();

private:
    void setLastSaveDate(const QDateTime& dateTime);
    QString lastSaveDate();
};

#endif // DRS4PROGRAMSETTINGSMANAGER_H
