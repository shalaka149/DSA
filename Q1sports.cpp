#include <iostream>
using namespace std;

const int MAX_TEAMS = 100;
const int MAX_MATCHES = 100;

void inputScores(int scores[MAX_TEAMS][MAX_MATCHES], int teams, int matches) {
    for (int i = 0; i < teams; ++i) {
        cout << "Enter scores for Team " << i + 1 << ":\n";
        for (int j = 0; j < matches; ++j) {
            cout << "  Match " << j + 1 << ": ";
            cin >> scores[i][j];
        }
    }
}

void calculateTotalScores(int scores[MAX_TEAMS][MAX_MATCHES], int totalScores[], int teams, int matches) {
    for (int i = 0; i < teams; ++i) {
        totalScores[i] = 0;
        for (int j = 0; j < matches; ++j) {
            totalScores[i] += scores[i][j];
        }
    }
}

int findHighestScoringTeam(int totalScores[], int teams) {
    int maxIndex = 0;
    for (int i = 1; i < teams; ++i) {
        if (totalScores[i] > totalScores[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void sortTeamsByTotal(int scores[MAX_TEAMS][MAX_MATCHES], int totalScores[],int teamNumbers[], int teams, int matches) {
    for (int i = 0; i < teams ; i++) {
        for (int j = i; j < teams; j++) {
            if (totalScores[i] < totalScores[j]) {
                // Swap total scores
                int tempScore = totalScores[i];
                totalScores[i] = totalScores[j];
                totalScores[j] = tempScore;

                // Swap team numbers
                int tempTeam = teamNumbers[i];
                teamNumbers[i] = teamNumbers[j];
                teamNumbers[j] = tempTeam;

                // Swap row scores
                for (int k = 0; k < matches; ++k) {
                    int temp = scores[i][k];
                    scores[i][k] = scores[j][k];
                    scores[j][k] = temp;
                }
            }
        }
    }
}

void displayScoreboard(int scores[][MAX_MATCHES], int totalScores[], int teamNumbers[], int teams, int matches) {
    cout << "\nScoreboard:(Highest to Lowest)\n";
    for (int i = 0; i < teams; ++i) {
        cout << "Team " << teamNumbers[i] << " scores: ";
        for (int j = 0; j < matches; ++j) {
            cout << scores[i][j] << " ";
        }
        cout << "| Total: " << totalScores[i] << "\n";
    }
}

int main() {
    int teams, matches;
    cout << "Enter number of teams: ";
    cin >> teams;
    cout << "Enter number of matches: ";
    cin >> matches;

    int scores[MAX_TEAMS][MAX_MATCHES];
    int totalScores[MAX_TEAMS];
    int teamNumbers[MAX_TEAMS];

    // Initialize team numbers
    for (int i = 0; i < teams; ++i) 
    {
        teamNumbers[i] = i + 1;
    }

    inputScores(scores, teams, matches);
    calculateTotalScores(scores, totalScores, teams, matches);

    int topTeam = findHighestScoringTeam(totalScores, teams);
    cout << "\nTeam " << teamNumbers[topTeam] << " has the highest total score: " << totalScores[topTeam] << "\n";

    sortTeamsByTotal(scores, totalScores, teamNumbers, teams, matches);
    displayScoreboard(scores, totalScores, teamNumbers, teams, matches);

    return 0;
}