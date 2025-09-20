#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#define MAX 5

struct Record {
    string name;
    int age;
};

struct List {
    Record data[MAX];
    int last;
};

class ADTList {
private:
    List L;
public:
    void makeNull();
    bool isFull();
    bool isEmpty();
    int locate(string n);
    void insert(Record x);
    void del(string n);
    void update(string n);
    void display();
    void save();
    void retrieve();
};

void ADTList::makeNull() {
    L.last = -1;
}

bool ADTList::isFull() {
    return L.last == MAX - 1;
}

bool ADTList::isEmpty() {
    return L.last == -1;
}

int ADTList::locate(string n) {
    for (int i = 0; i <= L.last; i++) {
        if (L.data[i].name == n) return i;
    }
    return -1;
}

void ADTList::insert(Record x) {
    if (isFull()) {
        cout << "List is full.\n";
        system("pause");
    } else {
        L.last++;
        L.data[L.last] = x;
        cout << x.name << " (" << x.age << ") was added.\n";
        system("pause");
    }
}

void ADTList::del(string n) {
    if (isEmpty()) {
        cout << "List is empty.\n";
        system("pause");
    } else {
        int p = locate(n);
        if (p < 0) {
            cout << "Not found.\n";
            system("pause");
        } else {
            for (int i = p; i < L.last; i++) {
                L.data[i] = L.data[i + 1];
            }
            L.last--;
            cout << n << " was removed.\n";
            system("pause");
        }
    }
}

void ADTList::update(string n) {
    if (isEmpty()) {
        cout << "List is empty.\n";
        system("pause");
    } else {
        int p = locate(n);
        if (p < 0) {
            cout << "Record not found.\n";
            system("pause");
        } else {
            int choice;
            do {
                system("cls");
                cout << "Updating record for: " << L.data[p].name << endl;
                cout << "Current age: " << L.data[p].age << endl;
                cout << "\n1.) Update Age\n";
                cout << "2.) Go Back\n";
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "Enter new age: ";
                    cin >> L.data[p].age;
                    cout << "Age updated successfully.\n";
                    system("pause");
                }

            } while (choice != 2);
        }
    }
}

void ADTList::display() {
    system("cls");
    if (isEmpty()) {
        cout << "List is empty.\n";
    } else {
        cout << "No.\tName\tAge\tRemarks\n";
        for (int i = 0; i <= L.last; i++) {
            cout << i + 1 << ".)\t" << L.data[i].name
                 << "\t" << L.data[i].age
                 << "\t" << (L.data[i].age >= 18 ? "ADULT" : "MINOR") << endl;
        }
    }
    system("pause");
    system("cls");
}

void ADTList::save() {
    ofstream fout("records.txt");
    for (int i = 0; i <= L.last; i++) {
        fout << L.data[i].name << " " << L.data[i].age << endl;
    }
    fout.close();
}

void ADTList::retrieve() {
    ifstream fin("records.txt");
    if (!fin) return;
    Record x;
    L.last = -1;
    while (fin >> x.name >> x.age) {
        if (!isFull()) {
            L.last++;
            L.data[L.last] = x;
        }
    }
    fin.close();
}

void menu() {
    cout << "MENU\n";
    cout << "1.) Insert\n";
    cout << "2.) Delete\n";
    cout << "3.) Display\n";
    cout << "4.) Update Age\n";
    cout << "5.) Exit\n";
}

int main() {
    ADTList list;
    Record x;
    int choice;

    list.makeNull();
    list.retrieve();

    while (true) {
        menu();
        cout << "Enter choice (1-5): ";
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> x.name;
                cout << "Enter age: ";
                cin >> x.age;
                list.insert(x);
                list.save();
                break;

            case 2:
                cout << "Enter name to delete: ";
                cin >> x.name;
                list.del(x.name);
                list.save();
                break;

            case 3:
                list.display();
                break;

            case 4:
                cout << "Enter name to update age: ";
                cin >> x.name;
                list.update(x.name);
                list.save();
                break;

            case 5:
                list.save();
                exit(0);

            default:
                cout << "Invalid choice. Try again.\n";
                system("pause");
                system("cls");
        }
    }
}
