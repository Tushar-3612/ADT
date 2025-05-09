#include <iostream>
using namespace std;

class MusicTrack {
public:
    int trackID;
    string trackName;
    string artistName;

    MusicTrack() {
        trackID = -1;
        trackName = "";
        artistName = "";
    }
};

class MusicLibrary {
    MusicTrack tracks[10];
    int occupied[10];

public:
    MusicLibrary() {
        for (int i = 0; i < 10; i++) {
            occupied[i] = -1; // -1 = never used, -2 = deleted, 1 = occupied
        }
    }

    void insert(MusicTrack track) {
        int index = track.trackID % 10;

        if (occupied[index] == -1 || occupied[index] == -2) {
            tracks[index] = track;
            occupied[index] = 1;
        } else {
            int i = (index + 1) % 10;
            while (i != index) {
                if (occupied[i] == -1 || occupied[i] == -2) {
                    tracks[i] = track;
                    occupied[i] = 1;
                    return;
                }
                i = (i + 1) % 10;
            }
            cout << "Library full! Could not add track ID: " << track.trackID << endl;
        }
    }

    void search(int trackID) {
        int index = trackID % 10;
        int i = index;

        while (occupied[i] != -1) {
            if (occupied[i] == 1 && tracks[i].trackID == trackID) {
                cout << "\nTrack Found at index " << i << ":\n";
                cout << "Track ID: " << tracks[i].trackID
                     << "\nTrack Name: " << tracks[i].trackName
                     << "\nArtist Name: " << tracks[i].artistName << endl;
                return;
            }
            i = (i + 1) % 10;
            if (i == index) break;
        }

        cout << "\nTrack with ID " << trackID << " not found in library.\n";
    }

    void deleteTrack(int trackID) {
        int index = trackID % 10;
        int i = index;

        while (occupied[i] != -1) {
            if (occupied[i] == 1 && tracks[i].trackID == trackID) {
                tracks[i] = MusicTrack(); // Reset track
                occupied[i] = -2; // Mark as deleted
                cout << "\nTrack with ID " << trackID << " deleted successfully.\n";
                return;
            }
            i = (i + 1) % 10;
            if (i == index) break;
        }

        cout << "\nTrack with ID " << trackID << " not found for deletion.\n";
    }

    void updateTrack(int trackID) {
        int index = trackID % 10;
        int i = index;

        while (occupied[i] != -1) {
            if (occupied[i] == 1 && tracks[i].trackID == trackID) {
                cout << "\nEnter new Track Name: ";
                cin.ignore();
                getline(cin, tracks[i].trackName);
                cout << "Enter new Artist Name: ";
                getline(cin, tracks[i].artistName);
                cout << "Track updated successfully.\n";
                return;
            }
            i = (i + 1) % 10;
            if (i == index) break;
        }

        cout << "\nTrack with ID " << trackID << " not found for update.\n";
    }

    void display() {
        cout << "\nMusic Library:\n";
        for (int i = 0; i < 10; i++) {
            if (occupied[i] == 1) {
                cout << i << ": [Track ID: " << tracks[i].trackID
                     << ", Track: " << tracks[i].trackName
                     << ", Artist: " << tracks[i].artistName << "]\n";
            } else if (occupied[i] == -2) {
                cout << i << ": Deleted\n";
            } else {
                cout << i << ": Empty\n";
            }
        }
    }
};

int main() {
    MusicLibrary library;
    int choice;

    do {
        cout << "\nMusic Library Menu:\n";
        cout << "1. Add Track\n";
        cout << "2. Display Library\n";
        cout << "3. Search Track by ID\n";
        cout << "4. Delete Track by ID\n";
        cout << "5. Update Track by ID\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            MusicTrack t;
            cout << "\nEnter Track ID: ";
            cin >> t.trackID;
            cin.ignore(); // Clear input buffer
            cout << "Enter Track Name: ";
            getline(cin, t.trackName);
            cout << "Enter Artist Name: ";
            getline(cin, t.artistName);
            library.insert(t);
            break;
        }

        case 2:
            library.display();
            break;

        case 3: {
            int id;
            cout << "\nEnter Track ID to search: ";
            cin >> id;
            library.search(id);
            break;
        }

        case 4: {
            int id;
            cout << "\nEnter Track ID to delete: ";
            cin >> id;
            library.deleteTrack(id);
            break;
        }

        case 5: {
            int id;
            cout << "\nEnter Track ID to update: ";
            cin >> id;
            library.updateTrack(id);
            break;
        }

        case 6:
            cout << "Exiting ...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
