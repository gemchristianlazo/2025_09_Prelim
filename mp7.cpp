//Using Doubly Link List of structures (name,age)
#include <iostream>
#include <fstream>
using namespace std;
struct Record {
string name;
int age;
};
struct Node {
   Record data;
   struct Node *next;
   struct Node *prev;
   Node(Record x) : data(x),next(NULL),prev(NULL) {}
};
class MyLink {
private:
    Node *head;
    Node *tail;
public:
    MyLink() : head(NULL),tail(NULL){}//Constructor that initializes head = NULL;
   ~MyLink() {//Destructor that is automatically called when the program terminates
    Node *p,*t;
    p = head;
    while (p!=NULL){
        t = p;
        p = p->next;
        delete(t);
     }
     head=NULL;
     tail=NULL;
    }
    void add(Record x);
    void del(string n);
    void display();
    void save();
    void retrieve();
};

int menu();

int main(){
Record x;
MyLink obj;//obj object
obj.retrieve();
while(1){
    switch(menu()){
    case 1 : system("cls");printf("Add Data Mode\n");
             cin.ignore();
             cout<<"Input Name: "; getline(cin,x.name);
             cout<<"Input Age: "; cin>>x.age;
             obj.add(x);obj.save();break;
    case 2 : system("cls");printf("Delete Data Mode\n");
             cin.ignore();
             cout<<"Input Name: ";getline(cin,x.name);
             obj.del(x.name);obj.save();break;
    case 3 : obj.display();break;
    case 4 : obj.save();exit(0);
    default: cout<<("\n1 to 4 only.\n");system("pause");

    }
}

return 0;
}
int menu(){
int op;
system("cls");
cout<<"MENU\n";
cout<<"1.) Add data\n";
cout<<"2.) Delete data\n";
cout<<"3.) Display All\n";
cout<<"4.) Exit\n";
cout<<"Select(1-4): ";
cin>>op;
return op;
}

void MyLink::add(Record x){
Node *newNode;
newNode = new Node(x);
if (head == NULL) {//check if first node
    head = tail = newNode;
    }
else {
     tail->next = newNode;
     newNode->prev = tail;
     tail = newNode;
    }
cout << "Record of " << x.name << " added to the list." << endl;
system("pause");
}
void MyLink::del(string n){
Node *p;
p = head;
if (head == NULL) {
     cout << "List is empty." << endl;
     system("pause");
     return;
}

while (p != NULL && p->data.name != n) {
    p = p->next;
}
if (p == NULL) {
  cout << "Record of " << n << " not found." << endl;
  system("pause");
  return;
  }

// If it's the only node
if (p == head && p == tail) {
    head = tail = NULL;
}
// If removing head
else if (p == head) {
    head = head->next;
    head->prev = NULL;
   }
// If removing tail
else if (p == tail) {
   tail = tail->prev;
   tail->next = NULL;
   }
// If removing in the middle
   else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
    }

delete p;
cout << "Record of " << n << " removed." << endl;
system("pause");
}

void MyLink::display(){
int i=1;
Node *p = head;

system("cls");
printf(" NAME\t\t\tAGE\tREMARKS\n");
while (p!=NULL){
    cout<<i++<<".) "<<p->data.name<<"\t\t"<<p->data.age<<"\t"<<(p->data.age>=18? "ADULT":"MINOR")<<endl;
    p = p->next;
}
system("pause");
}
void MyLink::save(){
ofstream outFile("students.txt");
Node *p = head;
        if (!outFile) {
            cout << "Error opening file for saving!\n";
            return;
        }
        while (p!=NULL){
            outFile << p->data.name << "," << p->data.age << endl;
            p = p->next;
        }
        outFile.close();
        cout << "Records saved successfully.\n";
}
void MyLink::retrieve(){
Record d;
ifstream inFile("students.txt");
    if (!inFile) {
        cout << "No saved records found.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
            if (line.empty())
                continue;

            int pos = line.find(',');//the first occurrence of ',' from left to right
            if (pos<0)
                continue;
            else
            {
            d.name = line.substr(0, pos);
            d.age = stoi(line.substr(pos + 1));
            add(d);
        }
    }

    inFile.close();
    cout << "Records retrieved successfully.\n";
}

