#include <iostream>
#include <cmath>
using namespace std;

class Medical {
public:
    string patientName;
    int patientAge;
    int patientId;
    string patientDisease;
    string gender;

    Medical() {
        patientId = -1;
        patientAge = 0;
        patientDisease = "";
        patientName = "";
        gender = "";
    }

    void setData(int id, int age, string name, string dis, string gen) {
        patientId = id;
        patientAge = age;
        patientName = name;
        gender = gen;
        patientDisease = dis;
    }

    void display() {
        if (patientId != -1) {
            cout << "PatientID: " << patientId;
            cout << " | Age: " << patientAge;
            cout << " | Name: " << patientName;
            cout << " | Disease: " << patientDisease;
            cout << " | Gender: " << gender << endl;
        } else {
            cout << "Empty Slot" << endl;
        }
    }
};

class Hash {
private:
    Medical hashTable[100];

public:
    int size;
    Hash(int s) {
        size = s;
    }

    int hashFunction(int key) {
        return key % size;
    }

    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }

    int getPrime() {
        for (int i = size - 1; i >= 2; i--)
            if (isPrime(i))
                return i;
        return 3;
    }

    void insert(int id, int age, string name, string dis, string gen) {
        int index = hashFunction(id);
        int index1 = index;
        int prime = getPrime();
        int index2 = prime - (id % prime);
        int i = 0;

        while (hashTable[index].patientId != -1) {
            cout<<"Collision Occurs At index :"<<index <<endl;
            i++;
            index = (index1 + i * index2) % size;
            if (i == size) return;
        }

        hashTable[index].setData(id, age, name, dis, gen);
        cout << "\nRecord inserted at index " << index << endl;
    }

    void displayRecord() {
        for (int i = 0; i < size; i++) {
            cout << i << " -> ";
            hashTable[i].display();
        }
    }

    bool search(int id) {
        int index = hashFunction(id);
        int index1 = index;
        int prime = getPrime();
        int index2 = prime - (id % prime);
        int i = 0;

        while (hashTable[index].patientId != -1) {
            if (hashTable[index].patientId == id)
                return true;
            i++;
            index = (index1 + i * index2) % size;
        }

        return false;
    }

    void update(int id) {
        int index = hashFunction(id);
        int index1 = index;
        int prime = getPrime();
        int index2 = prime - (id % prime);
        int i = 0;

        while (hashTable[index].patientId != -1) {
            if (hashTable[index].patientId == id) {
                int age;
                string name, dis, gen;
                cout << "Enter new Age: "; cin >> age;
                cout << "Enter new Name: "; cin >> name;
                cout << "Enter new Disease: "; cin >> dis;
                cout << "Enter new Gender: "; cin >> gen;
                hashTable[index].setData(id, age, name, dis, gen);
                cout << "Patient record updated.\n";
                return;
            }
            i++;
            index = (index1 + i * index2) % size;
        }

        cout << "Patient not found.\n";
    }

    void deleteRecord(int id) {
        int index = hashFunction(id);
        int index1 = index;
        int prime = getPrime();
        int index2 = prime - (id % prime);
        int i = 0;

        while (hashTable[index].patientId != -1) {
            if (hashTable[index].patientId == id) {
                hashTable[index] = Medical(); 
                cout << "Record deleted.\n";
                return;
            }
            i++;
            index = (index1 + i * index2) % size;
        }

        cout << "Patient not found.\n";
    }

    void avgAge() {
        int total = 0, count = 0;
        for (int i = 0; i < size; i++) {
            if (hashTable[i].patientId != -1) {
                total += hashTable[i].patientAge;
                count++;
            }
        }
        if (count == 0) {
            cout << "No records found.\n";
        } else {
            cout << "Average Age of Patients: " << (total / count) << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter table size: ";
    cin >> size;
    Hash h(size);

    int ch, id, age;
    string name, dis, gen;

    while (1) {
        cout << "\n--- Medical Operation Menu ---\n";
        cout << "1. Add Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search by ID\n";
        cout << "4. Update Record\n";
        cout << "5. Delete Record\n";
        cout << "6. Average Age of Patients\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter ID, Age, Name, Disease, Gender:\n";
                cin >> id >> age >> name >> dis >> gen;
                h.insert(id, age, name, dis, gen);
                break;
            case 2:
                h.displayRecord();
                break;
            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                if (h.search(id))
                    cout << "Patient found.\n";
                else
                    cout << "Patient not found.\n";
                break;
            case 4:
                cout << "Enter ID to update: ";
                cin >> id;
                h.update(id);
                break;
            case 5:
                cout << "Enter ID to delete: ";
                cin >> id;
                h.deleteRecord(id);
                break;
            case 6:
                h.avgAge();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
	
