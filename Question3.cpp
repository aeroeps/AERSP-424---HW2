#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <mutex>
#include <chrono> // Include chrono for time measurements

using namespace std;

mutex coutMutex;
mutex ATCMutex;

bool ATC_Sleeping = true;
int numberOfAirplanes = 0;
bool redirected = false;
bool lastPlane = false;

void airplane(int number) 
{
    // Request to land
    {
        unique_lock<std::mutex> lock(ATCMutex);
        if (ATC_Sleeping) 
        {
            lock_guard<std::mutex> coutLock(coutMutex);
            cout << "Airplane #" << number << " is establishing communication with the ATC." << endl;
            ATC_Sleeping = false;
        }
        if (numberOfAirplanes >= 3 && !redirected) 
        {
            lock_guard<std::mutex> coutLock(coutMutex);
            cout << "Airplane #" << number << " requesting landing." << endl;
            cout << "Approach pattern full. Airplane #" << number << " redirected to another airport." << endl;
            redirected = true;
            return;
        }
        lock_guard<std::mutex> coutLock(coutMutex);
        cout << "Airplane #" << number << " requesting landing." << endl;
        cout << "Airplane #" << number << " is cleared to land." << endl;
        this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate landing
        numberOfAirplanes++;
    }
    
    // Land
     this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate landing
    
    // Remove from traffic pattern
    {
        lock_guard<std::mutex> lock(ATCMutex);
        numberOfAirplanes--;
        if (numberOfAirplanes == 0) {
            lock_guard<std::mutex> coutLock(coutMutex);
            cout << "Runway is now free." << endl;
            ATC_Sleeping = true;
            redirected = false;
        }
    }

    // Check if this is the last airplane to land at this airport
    if (number == 10) {
        lastPlane = true;
    }
}

int main() {
    auto start = chrono::steady_clock::now(); // Start the timer
    
    vector<std::thread> aircraftThreads;
    
    for (int i = 1; i <= 10; ++i)
    {
        aircraftThreads.emplace_back(airplane, i);
        random_device rd;
        mt19937 gen(rd());
    
        // Define the range
        int min = 0;
        int max = 2000;
    
        // Generate a random number between min and max (inclusive)
        uniform_int_distribution<> dis(min, max);
        int time = dis(gen);

        this_thread::sleep_for(std::chrono::milliseconds(time)); // Simulate landing

    } 

    // Join all threads
    for (auto& thread : aircraftThreads) 
    {
        thread.join();
    }
    
    auto end = chrono::steady_clock::now(); // End the timer
    chrono::duration<double> elapsed_seconds = end - start; // Calculate the duration
    
    cout << "Program duration: " << elapsed_seconds.count() << " seconds." << endl;
    
    return 0;
}