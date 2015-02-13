// FILE: carwash.cxx
// A small test program to test the car_wash_simulate function.

#include <iostream>   // Provides cout
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <queue>      // Provides queue
#include "washing.h"  // Provides averager, bool_source, washer
using namespace std;
using namespace main_savitch_8A;

void car_wash_simulate
(unsigned int wash_time, double arrival_prob, unsigned int total_time, unsigned int maxLength);
// Precondition: 0 <= arrival_prob <= 1.
// Postcondition: The function has simulated a car wash where wash_time is the
// number of seconds needed to wash one car, arrival_prob is the probability
// of a customer arriving in any second, total_time is the total number
// of seconds for the simulation and maxLength is max length of the queue before customer left.
// Before the simulation, the function has written its three parameters to cout.
// After the simulation, the function has written two pieces of information
// to cout: (1) The number of cars washed, and (2) The average waiting time of a customer.

int main( )
{
    // Wash takes 500 seconds
    // Customers arrive on average once every 400 seconds
    // Total simulation time is 6000 seconds
    car_wash_simulate(500, 1.0/400, 6000, 5);

    return EXIT_SUCCESS;
}

void car_wash_simulate
(unsigned int wash_time, double arrival_prob, unsigned int total_time, unsigned int maxLength)
// Library facilities used: iostream, queue, washing.h
{
    queue<unsigned int> arrival_times; // Waiting customer’s time stamps
    unsigned int next;                 // A value taken from the queue
    bool_source arrival(arrival_prob);
    washer machine(wash_time);
    averager wait_times;
    unsigned int current_second;
    unsigned int leftCustomers = 0;

    // Write the parameters to cout.
    cout << "Seconds to wash one car: " << wash_time << endl;
    cout << "Probability of customer arrival during a second: ";
    cout << arrival_prob << endl;
    cout << "Total simulation seconds: " << total_time << endl;      

    for (current_second = 1; current_second <= total_time; ++current_second)
    {   // Simulate the passage of one second of time.

        // Check whether a new customer has arrived.
        if (arrival.query( )) {
            if (arrival_times.size() < maxLength)
            {
                arrival_times.push(current_second);
            } else {
                leftCustomers ++;
            }
        }

        // Check whether we can start washing another car.
        if ((!machine.is_busy( ))  &&  (!arrival_times.empty( )))
        {
            next = arrival_times.front( );
            arrival_times.pop( );
            wait_times.next_number(current_second - next);
            machine.start_washing( );
        }

        // Tell the washer to simulate the passage of one second.
        machine.one_second( );
    }
    
    //Handle leftover cars.
    while (!arrival_times.empty()) {
        current_second ++;
        // Check whether we can start washing another car.
        if (!machine.is_busy( ))
        {
            next = arrival_times.front( );
            arrival_times.pop( );
            wait_times.next_number(current_second - next);
            machine.start_washing( );
        }

        // Tell the washer to simulate the passage of one second.
        machine.one_second( );
    }

    // Write the summary information about the simulation.
    cout << "Customers served: " << wait_times.how_many_numbers( ) << endl;
    cout << "Number of customers left due to the queue length: " << leftCustomers << endl;
    if (wait_times.how_many_numbers( ) > 0)
        cout << "Average wait: " << wait_times.average( ) << " sec" << endl;
}
