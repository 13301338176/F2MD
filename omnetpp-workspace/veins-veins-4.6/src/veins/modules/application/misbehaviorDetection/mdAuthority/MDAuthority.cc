/*******************************************************************************
* @author  Joseph Kamel
* @date    11/04/2014
* @version 1.0
*
* SCA (Secure Cooperative Autonomous systems)
* Copyright (c) 2013, 2018 Institut de Recherche Technologique SystemX
* All rights reserved.
*******************************************************************************/

#include "MDAuthority.h"

static char const *nameV1 = "mdaV1";
static char const *nameV2 = "mdaV2";

static MDABase baseV1(nameV1);
static MDABase baseV2(nameV2);

MDAuthority::MDAuthority() {

}

void MDAuthority::addNewNode(int id, double mbType, double time) {
    if (mbType == 1) {
        baseV1.addTotalFaulty(id, time);
        baseV2.addTotalFaulty(id, time);
    }
    if (mbType == 2) {
        baseV1.addTotalAttacker(id, time);
        baseV2.addTotalAttacker(id, time);
    }
}

void MDAuthority::sendReportV1(MBReport report) {
    treatReportV1(report);
}
void MDAuthority::sendReportV2(MBReport report) {
    treatReportV2(report);
}

void MDAuthority::treatReportV2(MBReport report) {
    if (report.getMbType() == 1) {
        if (!baseV2.alreadyReportedFaulty(report.getReportedId())) {
            baseV2.addReportedFaulty(report.getReportedId(),
                    report.getGenerationTime());
        }
    }
    if (report.getMbType() == 2) {
        if (!baseV2.alreadyReportedAttacker(report.getReportedId())) {
            baseV2.addReportedAttacker(report.getReportedId(),
                    report.getGenerationTime());
        }
    }
}

void MDAuthority::treatReportV1(MBReport report) {
    if (report.getMbType() == 1) {
        if (!baseV1.alreadyReportedFaulty(report.getReportedId())) {
            baseV1.addReportedFaulty(report.getReportedId(),
                    report.getGenerationTime());
        }
    }
    if (report.getMbType() == 2) {
        if (!baseV1.alreadyReportedAttacker(report.getReportedId())) {
            baseV1.addReportedAttacker(report.getReportedId(),
                    report.getGenerationTime());
        }
    }
}

static bool init = true;

void MDAuthority::saveLine(std::string path, std::string serial, double time) {
    char fileNameV1[] = "mdaResultV1.txt";
    char fileNameV2[] = "mdaResultV2.txt";

    char outChar[1024];
    char directoryPathGen[1024] = "";
    char filePathGen[1024] = "";
    const char * pathChar = path.c_str();
    const char * serialChar = serial.c_str();
    strcat(directoryPathGen, pathChar);
    strcat(directoryPathGen, serialChar);

    struct stat info;

    if (stat(directoryPathGen, &info) != 0) {
        mkdir(directoryPathGen, 0777);
    } else if (info.st_mode & S_IFDIR) {
    } else {
        mkdir(directoryPathGen, 0777);
    }

    strcpy(filePathGen, directoryPathGen);
    strcat(filePathGen, "/");
    strcat(filePathGen, fileNameV1);

    baseV1.getPrintable(outChar, time);
    baseV1.writeFile(filePathGen, outChar, init);

    strcpy(filePathGen, directoryPathGen);
    strcat(filePathGen, "/");
    strcat(filePathGen, fileNameV2);

    baseV2.getPrintable(outChar, time);
    baseV2.writeFile(filePathGen, outChar, init);

    if(init){
        init = false;
    }

}
