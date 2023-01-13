#include <iostream>
using namespace std;

struct Node{
    int data;
};

class Deque{
    private:
    Node * D;
    int N;
    int front, rear;
    public:
    Deque(int size){
        N = size;
        D = new Node[size];
        front = -1;
        rear = -1;
    }
    ~Deque(){
        delete[] D;
    }
    void Push_front(int value){
        if((front==0 && rear==N-1) || front==rear+1){
            cout<<"the Deque is full"<<endl;
            return; 
        }
        if (front <1)
        {
            front =N-1;
        }
        else
        {
            front--;
        }
        D[front].data = value;
        
    };
    void Push_back(int value){
        if((front==0 && rear==N-1) || front==rear+1){
            cout << "the Deque is full"<<endl;
            return;
        }
        if(front ==-1){
            front = 0;
        }
        rear++;
        D[rear].data = value;
    };
    Node *pop_front(){
        if(front ==-1){
            cout<<"The Deque is empty"<<endl;
            return NULL;
        }
        // Node* Aux &D[front];
        // if(front == rear){}
        /*falta codigo*/
    };
    Node *Pop_back(){
        if (front ==-1)
        {
            cout<<"The deque is empty"<<endl;
            return NULL;
        }
        Node* Aux =&D[rear];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = N-1;
        }
        else{
            rear--;
        }
        return Aux;
        
    };
    void Display(){
        if(front == -1){
            cout<<"The Deque is empty" <<endl;
            return;
        }
        cout << "Elements: ";
        int end = (front>rear)? (N-1):rear;
        for (int i = front; i <= end; i++)
        {
            cout<<D[i].data<<" ";
        }
        int ini = (front > rear)? 0:front;
        for (int i = ini; i <= rear; i++)
        {
            cout<< D[i].data<<" ";
        }
        cout<<endl;
        
    };
};

int main(){
    return 0;
    Deque DQ(4);
    DQ.Push_back(8);
    DQ.Push_back(5);
    DQ.Push_back(10);
    DQ.Push_back(12);
    DQ.Display();
    DQ.Push_back(11);
    DQ.Pop_back();
    DQ.pop_front();
    DQ.Display();
    DQ.Push_front(55);
    DQ.Push_back(45);
    DQ.Display();
}