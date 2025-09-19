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

int menu();

int main () {
    ADTList List;
    Record data;
    List.makeNull();
    List.retrieve();

    while(1){
        system("cls");
        switch(menu()){
            case 1:
                system("cls");
                cout << "Input name: ";
                cin >> data.name;
                cout << "Input age: ";
                cin >> data.age;
                List.add(data);
                List.save();
                break;
            case 2:
                system("cls");
                cout << "Input name: ";
                cin >> data.name;
                List.del(data.name);
                List.save();
                break;
            case 3:
                List.display();
                break;
            case 4:
                system("cls");
                cout << "Input name to update age: ";
                cin >> data.name;
                List.update(data.name);
                List.save();
                break;
            case 5:
                List.save();
                exit(0);
            default:
                cout << "Mali 1 to 5 lang.\n";
                system("pause");
        }
    }
    return 0;
}

int menu(){
    int op;
    cout << "Menu" << endl;
    cout << "1. Add" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Display all" << endl;
    cout << "4. Update age" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter choice (1-5): ";
    cin >> op;
    return op;
}

void ADTList::makeNull(){
    head = NULL;
}

void ADTList::save(){
    ofstream fout("records.txt");
    List *p = head;
    while(p != NULL){
        fout << p->data.name << " " << p->data.age << endl;
        p = p->next;
    }
    fout.close();
}

void ADTList::retrieve(){
    ifstream fin("records.txt");
    if (!fin) return;
    Record x;
    while (fin >> x.name >> x.age){
        add(x);
    }
    fin.close();
}

void ADTList::add(Record x){
    List *p, *q, *newNode;
    p = q = head;
    newNode = new List();
    newNode->data = x;

    while (p != NULL){
        q = p;
        p = p->next;
    }
    if (p == head){
        head = newNode;
    } else {
        q->next = newNode;
    }
    newNode->next = p;

    cout << x.name << " (" << x.age << ") was added." << endl;
    system("pause");
}

void ADTList::del(string name){
    List *q, *p;
    p = q = head;
    while (p != NULL && name != p->data.name){
        q = p;
        p = p->next;
    }
    if (p == NULL){
        cout << "Not found." << endl;
        system("pause");
    } else {
        if (p == head){
            head = p->next;
        } else {
            q->next = p->next;
        }
        delete (p);
        cout << name << " was removed." << endl;
        system("pause");
    }
}

void ADTList::update(string name){
    List *p = head;
    while (p != NULL && p->data.name != name){
        p = p->next;
    }
    if (p == NULL){
        cout << "Record not found." << endl;
        system("pause");
    } else {
        cout << "Current age of " << p->data.name
             << " is " << p->data.age << "." << endl;
        cout << "Enter new age: ";
        cin >> p->data.age;
        cout << "Age updated successfully." << endl;
        system("pause");
    }
}

void ADTList::display(){
    List *p;
    int i = 1;
    p = head;
    system("cls");

    if (p == NULL) {
        cout << "No records to display.\n";
        system("pause");
        return;
    }

    cout << "No.\tName\t\tAge\tRemarks" << endl;
    while (p != NULL){
        cout << i++ << ".)\t" << p->data.name
             << "\t\t" << p->data.age
             << "\t" << (p->data.age >= 18 ? "ADULT" : "MINOR") << endl;
        p = p->next;
    }
    cout << endl;
    system("pause");
}
