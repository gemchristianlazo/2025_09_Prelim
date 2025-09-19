#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define MAX 5

struct Record {
  string name;
  int age;
};

struct List {
  Record DATA[MAX];
  int last;
};

class ADTLIST {
  private:
    List L;

  public:
    void makeNull();
    bool isFull();
    int isEmpty();
    int locate(string n);

    void insert(Record x);
    void del(string name);
    void display();
};


int menu() {
    system("cls");
    int choice;
    cout << "MENU\n1. Add Record\n2. Delete Record\n3. Display Record\n4. Exit\nEnter choice: ";
    cin >> choice;
    return choice;
}

int main() {
  ADTLIST L;
  Record r;
  L.makeNull();

  while(true) {
    switch(menu()) {
      case 1:
        system("cls");
        cout << "Enter Name: ";
        cin >> r.name;
        cout << "Enter Age: ";
        cin >> r.age;
        L.insert(r);
        system("pause");
        break;

      case 2:
        system("cls");
        cout << "Enter name to delete: ";
        cin >> r.name;
        L.del(r.name);
        system("pause");
        break;

      case 3:
        system("cls");
        L.display();
        system("pause");
        break;

      case 4:
        return 0;

      default:
        cout << "Not valid." << endl;
        system("pause");
    }
  }
  return 0;
}

void ADTLIST::makeNull() {
  L.last = -1;
}

bool ADTLIST::isFull() {
  return (L.last >= MAX-1);
}

int ADTLIST::isEmpty() {
  return (L.last == -1);
}

int ADTLIST::locate(string n) {
  for (int i=0; i<=L.last; i++) {
    if (L.DATA[i].name == n) {
      return i;
    }
  }
  return -1;
}

void ADTLIST::insert(Record x) {
  if (isFull()) {
    cout << "List is full." << endl;
  }
  else {
    L.last++;
    L.DATA[L.last].age = x.age;
    L.DATA[L.last].name = x.name;
    cout << x.name << " is added." << endl;
  }
}

void ADTLIST::del(string name) {
  if (isEmpty()) {
    cout << "List is empty\n";
    return;
  }
  int p = locate(name);
  if (p < 0) {
    cout << "Data not found." << endl;
  }
  else {
    cout << name << " is deleted.\n" << endl;
    for(int i=p; i<L.last; i++) {
      L.DATA[i].name = L.DATA[i+1].name;
      L.DATA[i].age = L.DATA[i+1].age;
    }
    L.last--;
  }
}

void ADTLIST::display() {
  if (isEmpty()) {
    cout << "No records to display.\n";
    return;
  }
  cout << "   Name  \tAge\tRemarks" << endl;
  for (int i=0; i<=L.last; i++) {
    cout << (i+1) << ". " << L.DATA[i].name << "  \t"
         << L.DATA[i].age << "   \t"
         << (L.DATA[i].age <= 18 ? "Minor" : "Adult") << endl;
  }
  cout << "\n";
}
