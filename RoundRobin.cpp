#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int pid, burstTime, remainingTime, waitingTime, turnAroundTime, completionTime;
    Process(int id, int bt) : pid(id), burstTime(bt), remainingTime(bt),
                               waitingTime(0), turnAroundTime(0), completionTime(0) {}
};

int main() {
    // Process array with ID and Burst Time
    Process p1(1, 4);
    Process p2(2, 3);
    Process p3(3, 2);
    Process p4(4, 1);

    Process processes[] = {p1, p2, p3, p4};
    int n = sizeof(processes) / sizeof(processes[0]);

    int timeSlice = 2; // Time slice for Round Robin
    int currentTime = 0, totalWaitingTime = 0, totalTurnaroundTime = 0, totalCompletionTime = 0;

    // Round Robin Scheduling
    int i = 0;
    while (true) {
        bool allCompleted = true;
        for (int j = 0; j < n; j++) {
            Process &p = processes[j];
            if (p.remainingTime > 0) {
                allCompleted = false;
                int timeToExecute = (p.remainingTime > timeSlice) ? timeSlice : p.remainingTime;
                p.remainingTime -= timeToExecute;
                currentTime += timeToExecute;

                if (p.remainingTime == 0) {
                    p.completionTime = currentTime;
                    p.turnAroundTime = p.completionTime - p.pid;
                    p.waitingTime = p.turnAroundTime - p.burstTime;
                }

                cout << "Process " << p.pid << " executed for " << timeToExecute
                     << " units. Remaining time: " << p.remainingTime << endl;
            }
        }

        if (allCompleted) break;
    }

    // Calculate total times and display results
    for (int i = 0; i < n; i++) {
        Process &p = processes[i];
        totalWaitingTime += p.waitingTime;
        totalTurnaroundTime += p.turnAroundTime;
        totalCompletionTime += p.completionTime;

        cout << "Process " << p.pid << " - Burst Time: " << p.burstTime
             << ", Waiting Time: " << p.waitingTime
             << ", Turnaround Time: " << p.turnAroundTime
             << ", Completion Time: " << p.completionTime << endl;
    }

    cout << "Avg Waiting Time: " << (float)totalWaitingTime / n
         << ", Avg Turnaround Time: " << (float)totalTurnaroundTime / n
         << ", Avg Completion Time: " << (float)totalCompletionTime / n << endl;

    return 0;
}
