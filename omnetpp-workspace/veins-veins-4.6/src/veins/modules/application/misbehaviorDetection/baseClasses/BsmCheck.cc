/*******************************************************************************
* @author  Joseph Kamel
* @date    11/04/2014
* @version 1.0
*
* SCA (Secure Cooperative Autonomous systems)
* Copyright (c) 2013, 2018 Institut de Recherche Technologique SystemX
* All rights reserved.
*******************************************************************************/

#include "BsmCheck.h"

BsmCheck::BsmCheck() {
     rangePlausibility = 1;
     speedConsistancy = 1;
     positionConsistancy = 1;
     speedPlausibility = 1;
     positionSpeedConsistancy = 1;
     intersection = InterTest();
     suddenAppearence = 1;
     beaconFrequency = 1;
     positionPlausibility = 1;

     reported = false;
}

double BsmCheck::getRangePlausibility() {
    return rangePlausibility;
}

double BsmCheck::getPositionSpeedConsistancy() {
    return positionSpeedConsistancy;
}

double BsmCheck::getPositionConsistancy() {
    return positionConsistancy;
}

double BsmCheck::getSpeedConsistancy() {
    return speedConsistancy;
}

double BsmCheck::getSpeedPlausibility() {
    return speedPlausibility;
}

InterTest BsmCheck::getIntersection() {
    return intersection;
}

double BsmCheck::getSuddenAppearence() {
    return suddenAppearence;
}

double BsmCheck::getBeaconFrequency() {
    return beaconFrequency;
}

double BsmCheck::getPositionPlausibility() {
    return positionPlausibility;
}

bool BsmCheck::getReported() {
    return reported;
}

void BsmCheck::setRangePlausibility(double rangePlausibility) {
    this->rangePlausibility = rangePlausibility;
}

void BsmCheck::setPositionConsistancy(double positionConsistancy) {
    this->positionConsistancy = positionConsistancy;
}

void BsmCheck::setSpeedConsistancy(double speedConsistancy) {
    this->speedConsistancy = speedConsistancy;
}

void BsmCheck::setSpeedPlausibility(double speedPlausibility) {
    this->speedPlausibility = speedPlausibility;
}

void BsmCheck::setIntersection(InterTest intersection) {
    this->intersection = intersection;
}

void BsmCheck::setSuddenAppearence(double suddenAppearence) {
    this->suddenAppearence = suddenAppearence;
}

void BsmCheck::setBeaconFrequency(double beaconFrequency) {
    this->beaconFrequency = beaconFrequency;
}

void BsmCheck::setPositionPlausibility(double positionPlausibility) {
    this->positionPlausibility = positionPlausibility;
}

void BsmCheck::setPositionSpeedConsistancy(double positionSpeedConsistancy) {
    this->positionSpeedConsistancy = positionSpeedConsistancy;
}

void BsmCheck::setReported(bool reported) {
    this->reported = reported;
}


