#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int pid, burstTime, waitingTime, turnAroundTime, completionTime;
    Process(int id, int bt) : pid(id), burstTime(bt), waitingTime(0), turnAroundTime(0), completionTime(0) {}
};

int main() {
    queue<Process> processQueue;
    processQueue.push(Process(1, 4));
    processQueue.push(Process(2, 3));
    processQueue.push(Process(3, 2));
    processQueue.push(Process(4, 1));

    int currentTime = 0, totalWaitingTime = 0, totalTurnaroundTime = 0, totalCompletionTime = 0, n = processQueue.size();

    while (!processQueue.empty()) {
        Process &p = processQueue.front();
        p.waitingTime = currentTime;
        p.turnAroundTime = p.waitingTime + p.burstTime;
        p.completionTime = currentTime + p.burstTime;
        currentTime += p.burstTime;

        totalWaitingTime += p.waitingTime;
        totalTurnaroundTime += p.turnAroundTime;
        totalCompletionTime += p.completionTime;

        cout << "Process " << p.pid << " - Burst Time: " << p.burstTime
             << ", Waiting Time: " << p.waitingTime
             << ", Turnaround Time: " << p.turnAroundTime
             << ", Completion Time: " << p.completionTime << endl;

        processQueue.pop();
    }

    cout << "Avg Waiting Time: " << (float)totalWaitingTime / n
         << ", Avg Turnaround Time: " << (float)totalTurnaroundTime / n
         << ", Avg Completion Time: " << (float)totalCompletionTime / n << endl;

    return 0;
}
