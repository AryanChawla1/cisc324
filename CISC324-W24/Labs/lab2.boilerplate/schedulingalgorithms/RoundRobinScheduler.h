#ifndef ROUNDROBINSCHEDULER_H
#define ROUNDROBINSCHEDULER_H

#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include "Process.h"
#include "CPUScheduler.h"
using namespace std;

class RoundRobinScheduler : public CPUScheduler
{
    vector<Process> processes;
    queue<Process> p;
    int q;
public:
    RoundRobinScheduler(queue<Process> processes, int quantum) {
        p = processes;
        q = quantum;
    }
    void schedule() override;
    void calculateAverageWaitTime() override;
    void calculateAverageTurnAroundTime() override;
};

#endif
