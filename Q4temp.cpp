#include <iostream>
using namespace std;

int main() {
    int numDays;  // Variable to store the number of days
    double sum = 0.0;
    double highest, lowest, average;
    int countAboveCertainTemp = 0;
    int countEqualToAverage = 0;
    double thresholdTemp;

    // Ask the user how many days of temperature data to store
    cout << "Enter the number of days for temperature data: ";
    cin >> numDays;

    // Check for valid input
    if (numDays <= 0) {
        cout << "Please enter a valid number of days (greater than 0)." << endl;
        return 1;
    }

    // Array to store temperatures for the specified number of days
    double temperatures[numDays];

    // Input daily temperatures
    cout << "Enter the temperatures for " << numDays << " days: " << endl;
    for (int i = 0; i < numDays; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> temperatures[i];
        sum += temperatures[i];
    }

    // Calculate highest, lowest, and average temperature
    highest = temperatures[0];
    lowest = temperatures[0];
    for (int i = 1; i < numDays; i++) {
        if (temperatures[i] > highest) highest = temperatures[i];
        if (temperatures[i] < lowest) lowest = temperatures[i];
    }
    average = sum / numDays;

    // Input the threshold temperature
    cout << "Enter the temperature threshold: ";
    cin >> thresholdTemp;

    // Count days above threshold temperature
    for (int i = 0; i < numDays; i++) {
        if (temperatures[i] > thresholdTemp) {
            countAboveCertainTemp++;
        }
        if (temperatures[i] == average) {
            countEqualToAverage++;
        }
    }

    // Output the results
    cout << "Highest temperature: " << highest << "°C" << endl;
    cout << "Lowest temperature: " << lowest << "°C" << endl;

    // Output average temperature with 2 decimal places manually
    cout << "Average temperature: " << average<< "°C" << endl;

    cout << "Number of days above threshold temp " << thresholdTemp << "°C are: " << countAboveCertainTemp << endl;
    cout << "Number of days with temperature exactly equal to the average: " << countEqualToAverage << endl;

    return 0;
}
