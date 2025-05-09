#include<iostream>
#include<string>
using namespace std;

class Hash {
public:
    int data;
    int arr[100];
    int n;
    int size; // actual number of elements to insert

    Hash() {
        n = 100;
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }
    }

    int hashtable(int data) {
        return data % n;
    }

    void accept() {
        cout << "Enter how many songs you want to insert: ";
        cin >> size;

        for (int i = 0; i < size; i++) {
            int id;
            string song_name;
            string author;
             
            cout << "\nEnter The Song Id: ";
            cin >> id;
            cout << "Enter The Song Name: ";
            cin >> song_name;
            cout << "Enter The song Author :- ";
            cin >> author ;
            

            int index = hashtable(id);
            int startIndex = index;

            if (arr[index] == 0) {
                arr[index] = id;
                cout << "Music inserted successfully " << id << endl;
            } else {
                cout << "Collision occurred for " << id << " at index " << index << endl;
                while (arr[index] != 0) {
                    index = (index + 1) % n;
                    if (index == startIndex) {
                        cout << "Table is full: " << id << endl;
                        return;
                    }
                }
                arr[index] = id;
                cout << "Music inserted successfully after collision at index " << index << endl;
            }
        }
    }

    void search() {
        int data;
        cout << "Enter the id: ";
        cin >> data;
        int index = hashtable(data);
        int startindex = index;
        while (arr[index] != 0) {
            if (arr[index] == data) {
                cout << "id found at index " << index << endl;
                return;
            }
            index = (index + 1) % n;
            if (index == startindex) {
                break;
            }
        }
        cout << "id is not found please check again." << endl;
    }

    void Delete() {
        int data;
        cout << "Enter Song You Want Delete :- ";
        cin >> data;
        int index = hashtable(data);
        int startindex = index;

        while (arr[index] != 0) {
            if (arr[index] == data) {
                arr[index] = -1;
                cout << " Music Deleted Successfully at Index " << index << "!" << endl;
                return;
            }
            index = (index + 1) % n;
            if (index == startindex) {
                break;
            }
        }
        cout << "SONG IS NOT FOUND :- ";
    }

    void display() {
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0 && arr[i] != -1) {
                cout << "Index " << i << ": "  << arr[i] << endl;
                
            }
        }
    }
};

int main() {
    Hash h1;
    int choice;
    do {
        cout << "\n1. Insert Music\n2. Search Song\n3. Delete Song\n4. Display Playlist\n5. Exit";
        cout << "\nEnter Your Choice :- ";
        cin >> choice;
        switch (choice) {
            case 1:
                h1.accept();
                break;
            case 2:
                h1.search();
                break;
            case 3:
                h1.Delete();
                break;
            case 4:
                h1.display();
                break;
            case 5:
                cout << "Exiting Program :- ";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
