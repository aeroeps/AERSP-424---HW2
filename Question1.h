#ifndef Question1
#define Question1
#include <string>
#include <vector>

using namespace std;

// Question 1.1
class Sensor
{
    public:
        virtual void gatherData() const=0;
        virtual void processData() const=0;
        virtual ~Sensor() {} // This is a destructor for the sensor class

};

// Air Speed Sensor - Question 1.2
class AirSpeedSensor : public Sensor
{
    public:
        void gatherData() const override;
        void processData() const override;
};

// Temperature Sensor - Question 1.2
class TemperatureSensor : public Sensor
{
    public:
        void gatherData() const override;
        void processData() const override;
};

// Pressure Sensor - Question 1.2
class PressureSensor : public Sensor
{
    public:
        void gatherData() const override;
        void processData() const override;
};

// Question 1.3
class SensorFactory 
{
    public:
        static Sensor* createSensor(const string& type);
};


class AerospaceControlSystem
{
    private:
        vector<Sensor*> sensors;

    public:
        void addSensor(Sensor* sensor);
        void monitorAndAdjust(); 
};

# endif
