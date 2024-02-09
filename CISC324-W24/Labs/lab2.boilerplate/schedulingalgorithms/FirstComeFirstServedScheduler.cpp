#include "FirstComeFirstServedScheduler.h"
#include <iostream>
#include <algorithm>

void FirstComeFirstServedScheduler::schedule()
{
    // Implementation of FCFS scheduling

    while (!p.empty()) {
        list.push_back(p.front());
        p.pop();
    }

    sort(list.begin(), list.end(), [](const Process &a, const Process &b) {
        return a.arrivalTime < b.arrivalTime;
    });

    std::cout << "First come first serve process order:" << std::endl;
    int time = 0;
    for (const auto &process : list) {
        std::cout << "Process ID: " << process.id << ", Arrival Time: " << process.arrivalTime << ", Burst Time: " << process.burstTime << std::endl;
        time += process.burstTime;
    }

    std::cout << "Total Time: " << time << std::endl;
}

void FirstComeFirstServedScheduler::calculateAverageWaitTime() {
    int totalWaitTime = 0;
    int numProcesses = 0;
    int currentTime = 0;

    for (auto &process : list) {
        // Calculate wait time for the process
        process.waitTime = currentTime - process.arrivalTime;
        if (process.waitTime < 0) // If the process arrives after current time, no waiting time
            process.waitTime = 0;
        totalWaitTime += process.waitTime;
        // Update current time after the process execution
        currentTime += process.burstTime;
        numProcesses++;
    }

    double averageWaitTime = static_cast<double>(totalWaitTime) / numProcesses;
    std::cout << "Average Wait Time: " << averageWaitTime << std::endl;
}

void FirstComeFirstServedScheduler::calculateAverageTurnAroundTime() {
    int totalTurnAroundTime = 0;
    int numProcesses = 0;
    int currentTime = 0;

    for (auto &process : list) {
        // Calculate wait time for the process
        process.waitTime = currentTime - process.arrivalTime;
        if (process.waitTime < 0) // If the process arrives after current time, no waiting time
            process.waitTime = 0;
        // Turnaround time is wait time plus burst time
        totalTurnAroundTime += process.waitTime + process.burstTime;
        // Update current time after the process execution
        currentTime += process.burstTime;
        numProcesses++;
    }

    double averageTurnAroundTime = static_cast<double>(totalTurnAroundTime) / numProcesses;
    std::cout << "Average Turnaround Time: " << averageTurnAroundTime << std::endl;
}