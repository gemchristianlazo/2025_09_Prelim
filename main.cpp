#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 5
using namespace std;

struct Stack{
    int data[MAX];
    int top;

};

class ADTStack{
private:
    Stack S;
    int isfull();
    int isempty();

public:
    void makenull();
    void push(int x);
    void pop();
    void display();
    int top();

};

int menu();

int main()
{
    ADTStack stk;
    int x;
    stk.makenull();

    while(1){
        switch(menu()){
            case 1: system("cls");
                    cout << "Input number: ";
                    cin >> x;
                    stk.push(x);
                    system("pause");
                    break;

            case 2: system("cls");
                    stk.pop();
                    system("pause");
                    break;

            case 3: system("cls");
                    stk.display();
                    system("pause");
                    break;

            case 4: system("cls");
                    stk.top();
                    system("pause");
                    break;

            case 5: exit(0);
            default: cout << "Invalid Input!\n"; system("pause");

        }
    }
}

int menu()
{
    system("cls");
    int op;
    cout << "MENU";
    cout << "\n1.)PUSH\n";
    cout << "2.)POP\n";
    cout << "3.)DISPLAY\n";
    cout << "4.)TOP\n";
    cout << "5.)EXIT";
    cout << "\nSELECT: ";
    cin >> op;
    return op;
}

void ADTStack::makenull()
{
    S.top = MAX;
}

int ADTStack::isempty()
{
    return(S.top == MAX);
}

int ADTStack::isfull()
{
    return(S.top == 0);
}

void ADTStack::push(int x)
{
    if(isfull())
    {
        cout << "Stack Overflow!\n"; system("pause");return;
    }
    else {
        S.top--;
        S.data[S.top] = x;
    }
}

void ADTStack::pop()
{
    if(isempty())
    {
        cout << "Stack is empty!\n"; system("pause");return;

    }
    else {
        cout << "Popped: " << S.data[S.top] << endl;
        S.top++;
    }
}

void ADTStack::display()
{
    int ctr = 1;
    system("cls");
    cout << "The stack contains...\n";
    if(isempty()){
        cout << "No elements...\n"; return;
    } else{
        for(int i=S.top; i <MAX; i++){
        cout << ctr++ << ".) " << setw(5) << S.data[i] << endl;

    }

    }
}

int ADTStack::top()
{
    if(isempty()){
        cout << "Stack is empty!\n";
        return -1;
    }
    cout << "TOP ELEMENT: " << S.data[S.top] << endl;
    return S.data[S.top];
}
