#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Record {
    string name;
    int age;
};

struct List {
    Record data;
    List *next;
};

class ADTList {
private:
    List *head;
public:
    void makeNull();
    void add(Record x);
    void del(string n);
    void update(string n);
    void display();
    void save(const string &filename);
    void retrieve(const string &filename);
};

int menu();

int main () {
    ADTList list;
    Record data;
    list.makeNull();

    list.retrieve("people.txt");

    while (true) {
        system("cls");
        switch(menu()){
            case 1:
                system("cls");
                cout << "Input name: ";
                cin >> data.name;
                cout << "Input age: ";
                cin >> data.age;
                list.add(data);
                list.save("people.txt");
                break;
            case 2:
                system("cls");
                cout << "Input name to delete: ";
                cin >> data.name;
                list.del(data.name);
                list.save("people.txt");
                break;
            case 3:
                list.display();
                break;
            case 4:
                system("cls");
                cout << "Input name to update age: ";
                cin >> data.name;
                list.update(data.name);
                list.save("people.txt");
                break;
            case 5:
                list.save("people.txt");
                exit(0);
            default:
                cout << "Invalid input.\n";
                system("pause");
        }
    }
    return 0;
}

int menu(){
    int op;
    cout << "Menu\n";
    cout << "1. Add person\n";
    cout << "2. Delete person\n";
    cout << "3. Display all\n";
    cout << "4. Update age\n";
    cout << "5. Exit\n";
    cout << "Enter choice (1-5): ";
    cin >> op;
    return op;
}

void ADTList::makeNull(){
    head = NULL;
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
    } else{
        q->next = newNode;
    }
    newNode->next = p;

    cout << x.name << " (age " << x.age << ") was added." << endl;
    system("pause");
}

void ADTList::del(string n){
    List *q, *p;
    p = q = head;
    while (p != NULL && n != p->data.name){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        cout << "Not found." << endl;
    } else{
        if(p == head){
            head = p->next;
        } else{
            q->next = p->next;
        }
        delete (p);
        cout << n << " was removed." << endl;
    }
    system("pause");
}

void ADTList::update(string n){
    List *p = head;
    while (p != NULL && p->data.name != n){
        p = p->next;
    }
    if(p == NULL){
        cout << "Record not found." << endl;
    } else {
        cout << "Current age of " << p->data.name << " is " << p->data.age << "." << endl;
        cout << "Enter new age: ";
        cin >> p->data.age;
        cout << "Age updated successfully." << endl;
    }
    system("pause");
}

void ADTList::display(){
    List *p;
    int i = 1;
    p = head;
    system("cls");

    if (!p) {
        cout << "List is empty." << endl;
    } else {
        cout << "No.\tName\t\tAge\tRemarks\n";
        while (p != NULL){
            cout << i++ << ".)\t" << p->data.name << "\t\t" << p->data.age
                 << "\t" << (p->data.age >= 18 ? "ADULT" : "MINOR") << endl;
            p = p->next;
        }
    }
    system("pause");
}

void ADTList::save(const string &filename) {
    ofstream fout(filename);
    if (!fout) return;
    List *p = head;
    while (p != NULL) {
        fout << p->data.name << " " << p->data.age << endl;
        p = p->next;
    }
    fout.close();
}

void ADTList::retrieve(const string &filename) {
    ifstream fin(filename);
    if (!fin) return;
    Record x;
    while (fin >> x.name >> x.age) {
        add(x);
    }
    fin.close();
}
