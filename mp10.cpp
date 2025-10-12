#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int f;
public:
    Queue() : front(NULL), rear(NULL), f(0) {}
    bool isEmpty();
    int frOnt();
    void enque(int x);
    void deQue();
    void display();
    void makeNull();
};

int menu();

bool Queue::isEmpty() {
    return front == NULL;
}

int Queue::frOnt() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        system("pause");
        return -1;
    }
    return front->data;
}

void Queue::enque(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        Node *p, *q;
        p = q = front;
        while (p != NULL) {
            q = p;
            p = p->next;
        }
        rear = q;
        rear->next = newNode;
        rear = newNode;
    }
    cout << x << " is enqueued into the queue.\n";
    system("pause");
}

void Queue::deQue() {
    if (front) {
        Node* temp = front;
        cout << front->data << " is dequeued from the queue.\n";
        front = front->next;
        delete temp;
        f++;
        if (!front) {
            rear = NULL;
        }
    } else {
        cout << "Queue is empty.\n";
    }
    system("pause");
}

void Queue::display() {
    system("cls");
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        system("pause");
        return;
    }
    cout << "The Queue contains:\n";
    Node* current = front;
    int i = 0;
    while (current != NULL) {
        int index = (f + i) % 5;
        cout << i + 1 << ".) [" << index << "]" << current->data << endl;
        current = current->next;
        i++;
    }
    system("pause");
}

void Queue::makeNull() {
    while (front) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    front = NULL;
    rear = NULL;
    f = 0;
}

int main() {
    int n;
    Queue qu;
    qu.makeNull();
    while (true) {
        switch (menu()) {
        case 1:
            system("cls");
            cout << "Input x: ";
            cin >> n;
            qu.enque(n);
            break;
        case 2:
            qu.deQue();
            break;
        case 3:
            qu.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice.\n";
            system("pause");
        }
    }
    return 0;
}

int menu() {
    int ch;
    system("cls");
    cout << "MENU" << endl;
    cout << "1. Enque" << endl;
    cout << "2. Deque" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
    cout << "Select [1-4]: ";
    cin >> ch;
    return ch;
}
