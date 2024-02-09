#include "RoundRobinScheduler.h"

// This function is used as a comparison function to sort a vector
// by arrivalTime (ascending) and then ID (ascending)
// Given two Process return Boolean
bool compare(const Process& a, const Process& b) {
    if (a.arrivalTime < b.arrivalTime) {
        return true;
    }
    
    if (a.arrivalTime > b.arrivalTime) {
        return false;
    }

    return a.id < b.id;
}

// This function checks if there are any remaining Process left
// Takes vector of Process and returns Boolean
bool remainingTime(const vector<Process> a) {
    for (auto& process: a) {
        if (process.remainingTime != 0) {
            return true;
        }
    }
    return false;
}

void RoundRobinScheduler::schedule()
{
    // TODO: Implementation of Round Robin scheduling

    // Sorts queue by arrival time into a vector called processes
    // std::vector<Process> processes;
    while(!p.empty()) {
        processes.push_back(p.front());
        p.pop();
    }

    std::sort(processes.begin(), processes.end(), compare);

    /*
        At every round:
        1) are there any processes with remainingTime != 0
        2) Go to first process with remainingTime != 0
        3) Spend quantum time at it (or remainingTime if remainingTime < quantum)
        4) Check for another or new process
        5a) if there is, go back to 3)
        5b) If not, end round.

        things in background
        1) a clock to keep track of time
        2) adjusting wait period and remainingTime for all Process
    */
    int clock = 0; // clock to determine whether process can be used or not
    int counter[processes.size()] = { }; // this is to find waiting time, by storing time each process was worked on before final one
     // this is to check whether or not all processes are done
    while (remainingTime(processes)) {
        bool increment = true; // this is used to avoid infinite loop, explanation later
        // go through all Process
        for (int i = 0; i < processes.size(); i++) {
            // check if process arrived on time and if not completed
            if (processes[i].arrivalTime <= clock && processes[i].remainingTime != 0) {
                int interval = 0; // determine whether to remove q or less
                if (processes[i].remainingTime <= q) {
                    // if it is q or less then we can determine waiting time
                    interval = processes[i].remainingTime;
                    processes[i].waitTime = clock - counter[i];
                }
                else {
                    interval = q;
                }
                std::cout << "Process ID: " << processes[i].id << ": " << clock << " -> " << clock + interval << endl;
                clock += interval; // clock increases by interval
                counter[i] += interval; // store this so we now its not waiting time
                processes[i].remainingTime -= interval; // adjust remaining time
                increment = false; // clock does not need to increment
            }
            // this is when the process has not arrived yet, and thus all other ones to right also have not arrived, so new round
            else if (processes[i].arrivalTime > clock) {
                if (increment) { // this is to check if the clock needs to be incremented because no process was considered
                    clock += 1;
                }
                break; // new round
            }
        } 
    }
}

void RoundRobinScheduler::calculateAverageWaitTime()
{
    // TODO: Implementation of calculating average wait time
}

void RoundRobinScheduler::calculateAverageTurnAroundTime()
{
    // TODO: Implementation of calculating average turn around time
}