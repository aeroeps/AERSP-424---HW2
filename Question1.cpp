#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <memory>

#include <thread>
#include <mutex>


using namespace std;

// Question 1
class Sensor 
{
    public:
        virtual void gatherData() = 0;
        virtual void processData() = 0;
        virtual ~Sensor() {} // This is a destructor for the sensor class
};

class AirSpeedSensor : public Sensor 
{
    public:
        void gatherData() override 
        {
            // Simulate data gathering process for temperature sensor
            cout << "\nGathering data from Airspeed Sensor." << endl;
        }

        void processData() override 
        {
            // Simulate data processing for temperature sensor
            cout << "Processing data from Airspeed Sensor." << endl;
        }
};

class TemperatureSensor : public Sensor 
{
    public:
        void gatherData() override 
        {
            // Simulate data gathering process for pressure sensor
            cout << "Gathering data from Temperature Sensor." << endl;
        }

        void processData() override 
        {
            // Simulate data processing for pressure sensor
            cout << "Processing data from Temperature Sensor" << endl;
        }
};

class PressureSensor : public Sensor
{
    public:
        void gatherData() override
        {
            // Simulate data gathering process for position sensor
            cout << "Gathering data from Pressure Sensor." << endl;
        }

        void processData() override
        {
            // Simulate data processing for position sensor
            cout << "Processing data from Pressure Sensor." << endl;
        }
};

class SensorFactory
{
    public:
    static Sensor* createSensor(const string& type)
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
};

class AerospaceControlSystem 
{
    private:
        std::vector<Sensor*> sensors;

    public:
        void addSensor(Sensor* sensor) {
            sensors.push_back(sensor);
        }

        void monitorAndAdjust() {
            for (Sensor* sensor : sensors) {
                sensor->gatherData();
                sensor->processData();
                cout << "Adjusting controls based on sensor data." << endl;
            }
        }
};


int main() 
{
    cout << "\n #########################  QUESTION 1: #########################\n" << endl;
        AerospaceControlSystem ctrlSys;

            // Adding sensors
            ctrlSys.addSensor(SensorFactory::createSensor("Air Speed"));
            ctrlSys.addSensor(SensorFactory::createSensor("Temperature"));
            ctrlSys.addSensor(SensorFactory::createSensor("Pressure"));

            // Monitoring and adjusting
            ctrlSys.monitorAndAdjust();
    return 0;
}