#include <iostream>
#include "Question1.h"

// Air Speed Sensor - Question 1.2
void AirSpeedSensor::gatherData() const
{
    cout << "Gathering data from Air Speed Sensor." << endl;
}
void AirSpeedSensor::processData() const
{
    cout << "Processing data from Air Speed Sensor." << endl;
}

// Temperature Sensor - Question 1.2
void TemperatureSensor::gatherData() const 
{
    cout << "Gathering data from Temperature Sensor." << endl;
}
void TemperatureSensor::processData() const
{
    cout << "Processing data from Temperature Sensor." << endl;
}

// Pressure Sensor - Question 1.2
void PressureSensor::gatherData() const
{
    cout << "Gathering data from Pressure Sensor." << endl;
}

void PressureSensor::processData() const
{
    cout << "Processing data from Pressure Sensor." << endl;
}

Sensor* createSensor(const string& type)
{
    if (type == "Air Speed")
    {
        return new AirSpeedSensor();
    } 
    else if (type == "Temperature")
    {
        return new TemperatureSensor();
    }
    else if (type == "Pressure")
    {
        return new PressureSensor();
    } 
    else
    {
        return nullptr; // This is if there is no correct sensor asked for
    }
}


void AerospaceControlSystem::addSensor(Sensor* sensor)
{
    sensors.push_back(sensor);
}

void AerospaceControlSystem::monitorAndAdjust() 
{
    for (Sensor* sensor: sensors)
    {
        sensor->gatherData();
        sensor->processData();
        cout << "Adjusting controls based on sensor data." << endl;
    }
}


