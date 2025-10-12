#include <iostream>
#define MAX 5
using namespace std;
struct Qdata{
    int data[MAX];
    int f,r,ctr;
};

class Queue{
private:
    Qdata q;
    bool isempty();
    bool isfull();
    int frOnt();
public:
    void enque(int x);
    void deQue();
    void display();
    void makenull();
};

int menu();

int main(){
int n;
Queue qu;
qu.makenull();

while(true){
    switch(menu()){
    case 1: system("cls");cout<<"Input x: ";cin>>n;qu.enque(n);break;
    case 2: qu.deQue();break;
    case 3: qu.display();break;
    case 4: exit(0);
    default: cout<<"Invalid choice.\n";system("pause");
    }
}
return 0;


}

int menu(){
int ch;
system("cls");
cout<<"MENU"<<endl;
cout<<"1. Enque"<<endl;
cout<<"2. Deque"<<endl;
cout<<"3. Display"<<endl;
cout<<"4. Exit"<<endl;
cout<<"Select[1-4]: ";
cin>>ch;
return ch;
}

void Queue::makenull(){
q.f = q.r = -1;
q.ctr = 0;
}

bool Queue::isfull(){
return q.ctr == MAX;
}

bool Queue::isempty(){
return q.ctr == 0;
}

int Queue::frOnt(){
    return q.data[q.f];
}

void Queue::enque(int x){
if (isfull()) {
    cout<<"Queue is full.\n";
    system("pause");
    return;
}

if(isempty())
    q.f = q.r = 0;
else
    q.r = (q.r + 1) % MAX;

q.data[q.r] = x;
q.ctr++;

}

void Queue::deQue(){
if(isempty()){
    cout <<"Queue is empty.\n";
    system("pause");
    return;
}
cout<<frOnt()<<" is removed from the queue.\n";
system("pause");
q.f = (q.f + 1) % MAX;
q.ctr--;
}

void Queue::display(){
int i,index;
system("cls");
cout<<"The Queue contains: \n";
for (i=0;i<q.ctr;i++){
    index = (q.f + i) % MAX;
    cout <<i+1<<".) ["<<index<<"]"<<q.data[index]<<endl;
}
system("pause");
}
