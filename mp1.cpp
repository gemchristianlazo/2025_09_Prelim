#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 5

struct List {
  int DATA[MAX];
  int last;
};

class ADTLIST {
  private:
    List L;

  public:
  void makeNull();
  bool isFull();
  int isEmpty();
  int locate(int x);

  int menu(int choice);
  void insert(int x);
  void del(int x);
  void display();

};

int main() {
  ADTLIST L;
  L.makeNull();

  int choice, x;

  while(true) {
    switch(L.menu(choice)) {
      case 1:
        system("cls");
        cout << "\nEnter a number: ";
        cin >> x;
        L.insert(x);
        break;
      case 2:
        system("cls");
        cout << "\nEnter a number to delete: ";
        cin >> x;
        L.del(x);
        break;
      case 3:
        system("cls");
        L.display();
        break;
      case 4:
        return 0;
      default:
        cout << "Not valid." << endl;
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

int ADTLIST::locate(int x) {
  for (int i=0; i<=L.last; i++) {
    if (L.DATA[i] == x) {
      return i;
    }
  }
  return -1;
}


int ADTLIST::menu(int choice) {
  cout << "MENU \n1. Add Number\n2. Delete\n3. Display All\n4. Exit\nEnter choice: ";
  cin >> choice;
  return choice;
}

void ADTLIST::insert(int x) {
  if (isFull()) {
    cout << "List is full." << endl;
  }
  else {
    L.last++;
    L.DATA[L.last] = x;
    cout << x << " is added." << endl;
    return;
  }
}

void ADTLIST::del(int x) {
  if (isEmpty()) {
    cout << "List is empty\n";
    return;
  }
  int p = locate(x);
  if (p < 0) {
    cout << "Data not found." << endl;
  }
  else {
    cout << x << " is deleted.\n" << endl;
    for (int i=p; i<L.last; i++) {
      L.DATA[i] = L.DATA[i+1];
    }
    L.last--;
  }
}

void ADTLIST::display() {
  cout << "The list contains..." << endl;
  for (int i=0; i<=L.last; i++) {
    cout << (i+1) << ". " << L.DATA[i] << endl;
  }
  return;
}
