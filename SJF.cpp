#include <iostream>
using namespace std;

struct Process {
    int pid, burstTime, waitingTime, turnAroundTime, completionTime;
    Process(int id, int bt) : pid(id), burstTime(bt),
                               waitingTime(0), turnAroundTime(0), completionTime(0) {}
};

int main() {
    Process p1(1, 4);
    Process p2(2, 3);
    Process p3(3, 2);
    Process p4(4, 1);

    Process processes[] = {p1, p2, p3, p4};  // Array of processes
    int n = sizeof(processes) / sizeof(processes[0]);

    // Sort processes by burst time (Shortest Job First)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                // Swap processes
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int currentTime = 0, totalWaitingTime = 0, totalTurnaroundTime = 0, totalCompletionTime = 0;

    for (int i = 0; i < n; i++) {
        Process &p = processes[i];
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
    }

    cout << "Avg Waiting Time: " << (float)totalWaitingTime / n
         << ", Avg Turnaround Time: " << (float)totalTurnaroundTime / n
         << ", Avg Completion Time: " << (float)totalCompletionTime / n << endl;

    return 0;
}
