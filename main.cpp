#include <iostream> 
# include <string>

class Sensor
{
    public:
        virtual void gatherData() const = 0;
        virtual void processData() const = 0;
        virtual ~Sensor() {} // This is a destructor for the sensor class

};
