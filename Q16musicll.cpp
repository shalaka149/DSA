#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    Song* next;
    Song* prev;
};

class MusicPlaylist {
private:
    Song* head;
    Song* tail;

public:
    MusicPlaylist() : head(nullptr), tail(nullptr) {}

    // Add song at the end
    void addSong(string title, string artist) {
        Song* newSong = new Song{title, artist, nullptr, nullptr};

        if (tail == nullptr) {
            head = tail = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "Song added: " << title << " by " << artist << endl;
    }

    // Delete a song by title
    void deleteSong(string title) {
        Song* temp = head;

        while (temp != nullptr && temp->title != title) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Song not found: " << title << endl;
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        } else if (temp == tail) {
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Song deleted: " << title << endl;
    }

    // Traverse forward (play next song)
    void playNext() {
        if (head == nullptr) {
            cout << "No songs in playlist." << endl;
            return;
        }

        Song* temp = head;
        while (temp != nullptr) {
            cout << "Playing: " << temp->title << " by " << temp->artist << endl;
            temp = temp->next;
        }
    }

    // Traverse backward (play previous song)
    void playPrevious() {
        if (tail == nullptr) {
            cout << "No songs in playlist." << endl;
            return;
        }

        Song* temp = tail;
        while (temp != nullptr) {
            cout << "Playing: " << temp->title << " by " << temp->artist << endl;
            temp = temp->prev;
        }
    }

    // Display the playlist (all songs)
    void displayPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Song* temp = head;
        cout << "\nPlaylist:\n";
        while (temp != nullptr) {
            cout << temp->title << " by " << temp->artist << endl;
            temp = temp->next;
        }
    }

    // Shuffle playlist (randomize order)
    void shufflePlaylist() {
        // A simple shuffle implementation that reverses the playlist
        Song* temp = head;
        Song* newHead = nullptr;
        Song* newTail = nullptr;

        while (temp != nullptr) {
            Song* newSong = new Song{temp->title, temp->artist, nullptr, newTail};

            if (newTail != nullptr) {
                newTail->next = newSong;
            } else {
                newHead = newSong;
            }

            newTail = newSong;
            temp = temp->next;
        }

        head = newHead;
        tail = newTail;
        cout << "Playlist shuffled." << endl;
    }

    // Destructor to delete the playlist
    ~MusicPlaylist() {
        while (head != nullptr) {
            Song* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Playlist cleared." << endl;
    }
};

int main() {
    MusicPlaylist playlist;
    int choice;
    string title, artist;

    do {
        cout << "\n===== Music Playlist Menu =====\n";
        cout << "1. Add Song\n2. Delete Song\n3. Play Next Song\n4. Play Previous Song\n";
        cout << "5. Display Playlist\n6. Shuffle Playlist\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore any leftover newline character after reading choice

        switch (choice) {
        case 1:
            cout << "Enter song title: ";
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            playlist.addSong(title, artist);
            break;
        case 2:
            cout << "Enter song title to delete: ";
            getline(cin, title);
            playlist.deleteSong(title);
            break;
        case 3:
            playlist.playNext();
            break;
        case 4:
            playlist.playPrevious();
            break;
        case 5:
            playlist.displayPlaylist();
            break;
        case 6:
            playlist.shufflePlaylist();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
