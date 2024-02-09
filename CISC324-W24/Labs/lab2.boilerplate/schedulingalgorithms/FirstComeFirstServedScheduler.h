#ifndef FIRSTCOMEFIRSTSERVEDSCHEDULER_H
#define FIRSTCOMEFIRSTSERVEDSCHEDULER_H

#include <queue>
#include <vector>
#include <iostream>
#include "Process.h"
#include "CPUScheduler.h"
using namespace std;

class FirstComeFirstServedScheduler : public CPUScheduler
{
    vector<Process> list;
    queue<Process> p;
    int q;
public:
    FirstComeFirstServedScheduler(queue<Process> processes, int quantum) {
        p = processes;
        q = quantum;
    }
    void schedule() override;
    void calculateAverageWaitTime() override;
    void calculateAverageTurnAroundTime() override;
};

#endif
