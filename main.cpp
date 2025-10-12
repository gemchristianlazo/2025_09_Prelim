#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int ctr;
    bool isEmpty();
public:
    Stack();
    void push(int x);
    void pop();
    void display();
    void makeNull();
    int top(); // Added top() function
};

int menu();

Stack::Stack() {
    top = nullptr;
    ctr = 0;
}

bool Stack::isEmpty() {
    return ctr == 0;
}

void Stack::makeNull() {
    while (!isEmpty()) {
        pop();
    }
    top = nullptr;
    ctr = 0;
}

void Stack::push(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    ctr++;
    cout << x << " is pushed onto the stack.\n";
    system("pause");
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        system("pause");
        return;
    }
    Node* temp = top;
    cout << top->data << " is popped from the stack.\n";
    top = top->next;
    delete temp;
    ctr--;
    system("pause");
}

void Stack::display() {
    system("cls");
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        system("pause");
        return;
    }
    cout << "The Stack contains:\n";
    Node* current = top;
    int i = 1;
    while (current != nullptr) {
        cout << i << ".) " << current->data << endl;
        current = current->next;
        i++;
    }
    system("pause");
}

int Stack::top() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        system("pause");
        return -1;
    }
    cout << "TOP ELEMENT: " << top->data << endl;
    system("pause");
    return top->data;
}

int main() {
    int n;
    Stack st;
    st.makeNull();

    while (true) {
        switch (menu()) {
        case 1:
            system("cls");
            cout << "Input x: ";
            cin >> n;
            st.push(n);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.display();
            break;
        case 4:
            st.top(); // Added case for top()
            break;
        case 5:
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
    cout << "1.) Push" << endl;
    cout << "2.) Pop" << endl;
    cout << "3.) Display" << endl;
    cout << "4.) Top" << endl; // Added Top option
    cout << "5.) Exit" << endl;
    cout << "Select [1-5]: "; // Updated range to [1-5]
    cin >> ch;
    return ch;
}