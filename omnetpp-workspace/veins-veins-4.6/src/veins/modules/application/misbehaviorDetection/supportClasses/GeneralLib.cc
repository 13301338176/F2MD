/*******************************************************************************
* @author  Joseph Kamel
* @date    11/04/2014
* @version 1.0
*
* SCA (Secure Cooperative Autonomous systems)
* Copyright (c) 2013, 2018 Institut de Recherche Technologique SystemX
* All rights reserved.
*******************************************************************************/

#include "GeneralLib.h"

GeneralLib::GeneralLib(){
}

Coord GeneralLib::TypeToSize(std::string type){

    //lust
    if (type == "passenger1")
        return Coord(1.8,5.0 - 1.5 -1,0);
    if (type == "passenger2a")
        return Coord(1.8,4.5- 1.5 -1,0);
    if (type == "passenger2b")
        return Coord(1.8,4.5- 1.5 -1,0);
    if (type == "passenger3")
        return Coord(1.8,6.0- 1.5 -1,0);
    if (type == "passenger4")
        return Coord(1.8,5.5- 1.5 -1,0);
    if (type == "passenger5")
        return Coord(1.8,7.0- 2.5 -1,0);
    if (type == "bus")
        return Coord(1.8,12-3 -1,0);

    // irt
    if (type == "DEFAULT_VEHTYPE")
        return Coord(1.8,2.5 -1,0);
    if (type == "bait")
        return Coord(1.8,2.5 -1,0);
    if (type == "victim")
        return Coord(1.8,2.5 -1,0);
    if (type == "attacker")
        return Coord(1.8,2.5 -1,0);

}

double GeneralLib::RandomDouble(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int GeneralLib::RandomInt(int min, int max)
{
    int guess;
    guess = (rand() % (max - min + 1)) + min;
    return guess;
}
