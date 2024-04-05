#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <memory>

std::mutex coutMutex; // Mutex to guard std::cout

using namespace std;

class Robot
{
    public:
        int RobotNumber;
        int timeFinnishTask;
        int whileTime;
        mutex* mutex0; // tool 1
        mutex* mutex1; // tool 2
    
        Robot(int _number, mutex &tool0, mutex &tool1)
        :RobotNumber(_number), whileTime(0), mutex0(&tool0), mutex1(&tool1) {}

    
    void WorkOnTasks()
    {
        {
            lock_guard<std::mutex> lock(coutMutex);
            cout << "Robot " << RobotNumber << " is collecting data." << std::endl; // added
        }
        
        lock(*mutex0, *mutex1);
        lock_guard<std::mutex> leftLock( *mutex0, std::adopt_lock );
        lock_guard<std::mutex> rightLock( *mutex1, std::adopt_lock );
        {
            lock_guard<std::mutex> lock(coutMutex); // Lock access to std::cout
            cout << "Robot " << RobotNumber << " aquired tools and starts performing a task." << std::endl;
        }
        
        this_thread::sleep_for( std::chrono::seconds( 1 ) );
        this_thread::sleep_for( std::chrono::seconds( 5 ) );
        
        {
            lock_guard<std::mutex> lock(coutMutex); // Lock access to std::cout
            cout << "Robot " << RobotNumber << " finished the task and returning the tools." << std::endl;
        }

    }
};

class Arena
{
    private:
        vector<std::mutex> tools;
        vector<std::thread> tasks;
        vector<Robot> robots;
        int numRobots;
        chrono::steady_clock::time_point startTime;
        chrono::steady_clock::time_point endTime;
    
    public:
    Arena(int _numRobots)
    : tools(_numRobots), numRobots(_numRobots)
    {
        for (int i = 0; i < _numRobots; ++i)
            { robots.emplace_back(i + 1, tools[i], tools[(i+1)%5]); }
    }
    
    void simulateTasks()
    {
        // Record the start time
        startTime = chrono::steady_clock::now();
        
        // create 5 mutex for tools. have robot constructor receive two mutex. create 5 strands
        // use sleep_for for time to grab tools/complete tasks
        vector<std::thread> threads;
        // Create threads for each robot to perform tasks simultaneously
        for (int i = 0; i < numRobots; ++i) 
        { threads.push_back(thread(&Robot::WorkOnTasks, ref(robots[i]))); }
        // Wait for all threads to finish
        for (auto& thread : threads) { thread.join(); }

        // Record the end time
        endTime = chrono::steady_clock::now();
    }
    
    int getTotalTime() const
    { 
        // Calculate the duration between start and end times
        auto duration = chrono::duration_cast<chrono::seconds>(endTime - startTime);
        return duration.count(); // Return the total duration in seconds
    }
};
int main() 
{

    cout << "######################### QUESTION 2: #########################\n" << endl;

    int numRobots = 5;
    Arena arena(numRobots);
    
    // Simulate the tasks
    arena.simulateTasks();
    
    // Get the total time taken by all robots to finish their tasks
    int totalTime = arena.getTotalTime();
    cout << "Task time duration: " << totalTime << " seconds" << endl;
    
}