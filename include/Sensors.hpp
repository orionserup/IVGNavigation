#pragma once

#include "main.hpp"

#ifndef SIMULATION
#include "JetsonGPIO.h"
#include "CppLinuxSerial/Exception.hpp"
#include "CppLinuxSerial/SerialPort.hpp"

using namespace mn::CppLinuxSerial;
#endif

namespace igv{

class Magno{
public:

    Magno();

    void Probe();
    bool isBusy() { return busy; }

    bool CorrectOrientation(double deg1, double deg2);
    double GetDegree() { return Degree; }

private:

    //LIS2MDL angle;
    bool busy;
    double Degree;

    #ifndef SIMULATION

    SerialPort myport;

    #endif
};

class UltraSonic{

public:

    UltraSonic();
    double GetDistance(){ return this->distance; }  // returns the probed distance
    void Probe();  // gets a reading and puts it in the distance value
    bool isBusy() { return busy; }

private:

    bool busy;
    double distance;

};

}