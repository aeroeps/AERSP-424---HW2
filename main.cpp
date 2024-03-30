#include <iostream> 
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "Question1.h"


using namespace std;

const int number_robots = 5;
const int number_tools = 5;
const int time_to_tool = 1;
const int time_to_complete = 5;

mutex mtx;
condition_variable cv;
int taskCompeted = 0;
int wholeTime = 0;

void RobotPreformTask (int robotName, vector<int>& tools)
{
    int tool1 = robotName;
    int tool2 = (robotName + 1);

    // This is a stop so that the robots can put up the 
    unique_lock<mutex> lock (mtx);

    cv.wait(lock, [&] { return tools[tool1] == 2 && tools[tool2] == 2; });

    tools[tool1]--;
    tools[tool2]--;
    wholeTime += time_to_tool * 2;

    lock.unlock();

    this_thread::sleep_for(chrono::seconds(time_to_complete));

    lock.lock();
    tools[tool1]++;
    tools[tool2]++;
    wholeTime += time_to_complete * 2;


    taskCompeted++;

    if(taskCompeted == number_robots)
    {
        cv.notify_one();
    }
}

void Question2() 
{
    vector<int> tools(number_tools, 2); // Number of robots that need each tool
    vector<thread> threads;

    // Create threads for each robot for there tasks to be compleeted
    for (int i = 0; i < number_robots; ++i)
    {
        threads.emplace_back(RobotPreformTask, i, ref(tools));
    }

    // Wait for all threads to complete
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [&] { return taskCompeted == number_robots;});

    // Print total time taken
    cout << "Total time taken by all robots to finish all tasks: " << wholeTime << " seconds" << endl;

    // Join all threads
    for (auto& th : threads)
    {
        th.join();
    }
}


int main()
{

    // AerospaceControlSystem ctrlSys;

    // ctrlSys.addSensor(SensorFactory::createSensor("AirSpeed"));
    // ctrlSys.addSensor(SensorFactory::createSensor("Temperature"));
    // ctrlSys.addSensor(SensorFactory::createSensor("Pressure"));

    // ctrlSys.monitorAndAdjust();
    
    // // Print out line spacing
    // for (int i = 0; i < 3; ++i) 
    // {
    //     std::cout << std::endl; // Space
    // }
    cout <<"############################## Question 2 #########################################" << endl;
    
    Question2();
    
    return 0;
}