#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int box[100][100]; // Static array as requested

    // Input box weights
    cout << "Enter box weights row by row:\n";
    for (int i = 0; i < rows; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < cols; ++j) {
            cin >> box[i][j];
        }
    }

    // Initialize with the first element
    int heaviest = box[0][0];
    int lightest = box[0][0];

    // Find heaviest and lightest box
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (box[i][j] > heaviest)
                heaviest = box[i][j];
            if (box[i][j] < lightest)
                lightest = box[i][j];
        }
    }

    cout << "\nHeaviest box: " << heaviest << endl;
    cout << "Lightest box: " << lightest << endl;

    // Total weight per row
    cout << "\nTotal weight per row:\n";
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += box[i][j];
        }
        cout << "Row " << i + 1 << ": " << sum << endl;
    }

    // Swap two rows
    int r1, r2;
    cout << "\nEnter two row indices to swap (0-based): ";
    cin >> r1 >> r2;

    for (int j = 0; j < cols; ++j) {
        int temp = box[r1][j];
        box[r1][j] = box[r2][j];
        box[r2][j] = temp;
    }

    // Display after row swap
    cout << "\nAfter swapping rows " << r1 << " and " << r2 << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << box[i][j] << " ";
        }
        cout << endl;
    }

    // Swap two columns
    int c1, c2;
    cout << "\nEnter two column indices to swap (0-based): ";
    cin >> c1 >> c2;

    for (int i = 0; i < rows; ++i) {
        int temp = box[i][c1];
        box[i][c1] = box[i][c2];
        box[i][c2] = temp;
    }

    // Display after column swap
    cout << "\nAfter swapping columns " << c1 << " and " << c2 << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << box[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
