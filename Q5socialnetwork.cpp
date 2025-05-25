#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;

class Network {
    string users[MAX];
    int adj[MAX][MAX];
    int n;

public:
    Network() {
        n = 0;
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                adj[i][j] = 0;
    }

    int find(string name) {
        for (int i = 0; i < n; i++)
            if (users[i] == name) return i;
        return -1;
    }

    void addUser(string name) {
        if (find(name) == -1 && n < MAX) {
            users[n++] = name;
            cout << "User '" << name << "' added successfully!\n";
        } else {
            cout << "User already exists or limit reached.\n";
        }
    }

    void addFriend(string a, string b) {
        int i = find(a), j = find(b);
        if (i != -1 && j != -1) {
            adj[i][j] = adj[j][i] = 1;
            cout << "Friendship added between '" << a << "' and '" << b << "'!\n";
        } else {
            cout << "One or both users not found!\n";
        }
    }

    void removeFriend(string a, string b) {
        int i = find(a), j = find(b);
        if (i != -1 && j != -1 && adj[i][j]) {
            adj[i][j] = adj[j][i] = 0;
            cout << "Friendship removed between '" << a << "' and '" << b << "'.\n";
        } else {
            cout << "They are not friends.\n";
        }
    }

    void searchFriend(string a, string b) {
        int i = find(a), j = find(b);
        if (i != -1 && j != -1) {
            if (adj[i][j])
                cout << "'" << a << "' and '" << b << "' are Friends.\n";
            else
                cout << "'" << a << "' and '" << b << "' are NOT Friends.\n";
        } else {
            cout << "User(s) not found.\n";
        }
    }

    void suggestFriend(string name) {
        int idx = find(name);
        if (idx == -1) {
            cout << "User not found.\n";
            return;
        }

        int vis[MAX] = {0}, q[MAX];
        int front = 0, rear = 0, level = 0;
        vis[idx] = 1;
        q[rear++] = idx;

        cout << "Friend Suggestions for '" << name << "': ";
        bool found = false;

        while (front < rear && level < 2) {
            int size = rear - front;
            for (int i = 0; i < size; i++) {
                int u = q[front++];
                for (int v = 0; v < n; v++) {
                    if (adj[u][v] && !vis[v]) {
                        if (level == 1 && !adj[idx][v]) {
                            cout << users[v] << " ";
                            found = true;
                        }
                        vis[v] = 1;
                        q[rear++] = v;
                    }
                }
            }
            level++;
        }
        if (!found) cout << "No suggestions available.";
        cout << endl;
    }

    void displayNetwork(string name, int maxLevel) {
        int idx = find(name);
        if (idx == -1) {
            cout << "User not found.\n";
            return;
        }

        int vis[MAX] = {0}, q[MAX];
        int front = 0, rear = 0, level = 0;
        vis[idx] = 1;
        q[rear++] = idx;

        cout << "Friend Network of '" << name << "' up to level " << maxLevel << ":\n";

        while (front < rear && level <= maxLevel) {
            int size = rear - front;
            cout << "Level " << level << ": ";
            for (int i = 0; i < size; i++) {
                int u = q[front++];
                cout << users[u] << " ";
                for (int v = 0; v < n; v++) {
                    if (adj[u][v] && !vis[v]) {
                        vis[v] = 1;
                        q[rear++] = v;
                    }
                }
            }
            cout << endl;
            level++;
        }
    }
};

int main() {
    Network net;
    int ch, level;
    string a, b;

    cout << "====== Welcome to the Social Network ======\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add User\n";
        cout << "2. Add Friend\n";
        cout << "3. Remove Friend\n";
        cout << "4. Search Friend\n";
        cout << "5. Suggest Friends\n";
        cout << "6. Display Friend Network\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: cout << "Enter username: "; cin >> a; net.addUser(a); break;
            case 2: cout << "Enter two usernames: "; cin >> a >> b; net.addFriend(a, b); break;
            case 3: cout << "Enter two usernames: "; cin >> a >> b; net.removeFriend(a, b); break;
            case 4: cout << "Enter two usernames: "; cin >> a >> b; net.searchFriend(a, b); break;
            case 5: cout << "Enter username: "; cin >> a; net.suggestFriend(a); break;
            case 6: cout << "Enter username and max levels to display: "; cin >> a >> level; net.displayNetwork(a, level); break;
            case 7: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
