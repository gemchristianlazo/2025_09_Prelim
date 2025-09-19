#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct List {
    string name;
    int age;
    List *next;
};

class ADTList {
private:
    List *head;
public:
    void makeNull();
    void add(string n, int a);
    void del(string n);
    void display();
};

int menu();

int main () {
    ADTList List;
    string name;
    int age;
    List.makeNull();

    while(1){
        system("cls");
        switch(menu()){
            case 1:
                system("cls");
                cout<<"Input name: ";
                cin>>name;
                cout<<"Input age: ";
                cin>>age;
                List.add(name, age);
                break;
            case 2:
                system("cls");
                cout<<"Input name to delete: ";
                cin>>name;
                List.del(name);
                break;
            case 3:
                List.display();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Invalid input.\n";
                system("pause");
        }
    }
    return 0;
}

int menu(){
    int op;
    cout<<"Menu"<<endl;
    cout<<"1. Add person"<<endl;
    cout<<"2. Delete person"<<endl;
    cout<<"3. Display all"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter choice (1-4): ";
    cin>>op;
    return op;
}

void ADTList::makeNull(){
    head = NULL;
}

void ADTList::add(string n, int a){
    List *p, *q, *newNode;
    p = q = head;
    newNode = new List();
    newNode->name = n;
    newNode->age = a;

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

    cout<<n<<" (age "<<a<<") was added."<<endl;
    system("pause");
}

void ADTList::del(string n){
    List *q, *p;
    p = q = head;
    while (p != NULL && n != p->name){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        cout<<"Not found."<<endl;
        system("pause");
    } else{
        if(p == head){
            head = p->next;
        } else{
            q->next = p->next;
        }
        delete (p);
        cout<<n<<" was removed."<<endl;
        system("pause");
    }
}

void ADTList::display(){
    List *p;
    int i=1;
    p = head;
    system("cls");

    if (p == NULL) {
        cout << "List is empty.\n";
        system("pause");
        return;
    }

    cout << "No.\tName\t\tAge\tRemarks\n";
    while (p != NULL){
        cout << i++ << ".)\t"
             << p->name << "\t\t"
             << p->age << "\t"
             << (p->age > 17 ? "ADULT" : "MINOR")
             << endl;
        p = p->next;
    }
    system("pause");
}
