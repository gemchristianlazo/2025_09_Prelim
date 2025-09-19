#include <iostream>
#include <cstdlib>  // for system()
using namespace std;

struct List {
    int data;
    List *next;
};

class ADTList {
private:
    List *head;
public:
    void makeNull();
    void add(int x);
    void del(int x);
    void display();
};

int menu();

int main () {
    ADTList L;
    int num;
    L.makeNull();

    while(1){
        system("cls");
        switch(menu()){
            case 1:
                system("cls");
                cout<<"Input number: ";
                cin>>num;
                L.add(num);
                break;
            case 2:
                system("cls");
                cout<<"Input number to delete: ";
                cin>>num;
                L.del(num);
                break;
            case 3:
                L.display();
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
    cout<<"1. Add number"<<endl;
    cout<<"2. Delete number"<<endl;
    cout<<"3. Display all"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter choice (1-4): ";
    cin>>op;
    return op;
}

void ADTList::makeNull(){
    head = NULL;
}

void ADTList::add(int x){
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

    cout<<x<<" was added."<<endl;
    system("pause");
}

void ADTList::del(int x){
    List *q, *p;
    p = q = head;
    while (p != NULL && x != p->data){
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
        cout<<x<<" was removed."<<endl;
        system("pause");
    }
}

void ADTList::display(){
    List *p;
    int i=1;
    p = head;
    system("cls");
    cout<<"List elements: \n";
    while (p != NULL){
        cout<<i++<<".) "<<p->data<<endl;
        p = p->next;
    }
    system("pause");
}
