#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct Record {
    string name;
    int age;
};

struct List {
    Record data;
    List* next;
};

class ADTList {
private:
    List* head;
public:
    void makeNull();
    void add(Record x);
    void del(string name);
    void update(string name);
    void display();
    void save();
    void retrieve();
};

int menu() {
    int op;
    cout << "MENU\n";
    cout << "1.) Add\n";
    cout << "2.) Delete\n";
    cout << "3.) Display All\n";
    cout << "4.) Update Age\n";
    cout << "5.) Exit\n";
    cout << "Enter choice (1-5): ";
    cin >> op;
    return op;
}

int main() {
    ADTList list;
    Record data;
    int choice;

    list.makeNull();
    list.retrieve();

    while (true) {
        system("cls");
        choice = menu();
        system("cls");

        switch (choice) {
            case 1:
                cout << "Input name: ";
                cin >> data.name;
                cout << "Input age: ";
                cin >> data.age;
                list.add(data);
                list.save();
                break;

            case 2:
                cout << "Input name to delete: ";
                cin >> data.name;
                list.del(data.name);
                list.save();
                break;

            case 3:
                list.display();
                break;

            case 4:
                cout << "Input name to update age: ";
                cin >> data.name;
                list.update(data.name);
                list.save();
                break;

            case 5:
                list.save();
                exit(0);

            default:
                cout << "Invalid choice. 1-5 only.\n";
                system("pause");
        }
    }

    return 0;
}

void ADTList::makeNull() {
    head = NULL;
}

void ADTList::add(Record x) {
    List* newNode = new List();
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        List* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }

    cout << x.name << " (" << x.age << ") was added." << endl;
    system("pause");
}

void ADTList::del(string name) {
    if (head == NULL) {
        cout << "List is empty.\n";
        system("pause");
        return;
    }

    List* p = head;
    List* q = NULL;

    while (p != NULL && p->data.name != name) {
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Record not found.\n";
        system("pause");
    } else {
        if (p == head) {
            head = head->next;
        } else {
            q->next = p->next;
        }
        delete p;
        cout << name << " was removed.\n";
        system("pause");
    }
}

void ADTList::update(string name) {
    List* p = head;
    while (p != NULL && p->data.name != name) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Record not found.\n";
        system("pause");
    } else {
        int choice;
        do {
            system("cls");
            cout << "Current age of " << p->data.name
                 << " is " << p->data.age << ".\n";
            cout << "1.) Update age\n";
            cout << "2.) Back to menu\n";
            cout << "Choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter new age: ";
                cin >> p->data.age;
                cout << "Age updated successfully.\n";
                system("pause");
            }
        } while (choice != 2);
    }
}

void ADTList::display() {
    system("cls");
    if (head == NULL) {
        cout << "No records to display.\n";
        system("pause");
        return;
    }

    List* p = head;
    int i = 1;
    cout << "No.\tName\tAge\tRemarks\n";

    while (p != NULL) {
        cout << i++ << ".)\t"
             << p->data.name << "\t"
             << p->data.age << "\t"
             << (p->data.age >= 18 ? "ADULT" : "MINOR")
             << endl;
        p = p->next;
    }
    system("pause");
}

void ADTList::save() {
    ofstream fout("records.txt");
    List* p = head;
    while (p != NULL) {
        fout << p->data.name << " " << p->data.age << endl;
        p = p->next;
    }
    fout.close();
}

void ADTList::retrieve() {
    ifstream fin("records.txt");
    if (!fin) return;
    Record x;
    while (fin >> x.name >> x.age) {
        add(x);
    }
    fin.close();
}
