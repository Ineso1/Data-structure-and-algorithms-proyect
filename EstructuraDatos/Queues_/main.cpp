#include <iostream>
using namespace std;

struct Node
{
    int value;
};

class Queue{
    private:
        Node* Q;
        int front, rear, N;
    public:
        Queue(int size){
            N = size;
            Q = new Node[size];
            front = -1;
            rear = -1;
        }
        ~Queue(){
            delete[] Q;
        }
        void Enqueue(int n){
            if(front == 0 && rear == N-1){
                cout << "Queue is full" << endl;
                return;
            }
            if(front == -1){
                front = 0;
                rear++;
                Q[rear].value = n;
            }

        }
        Node* Dequeue(){
            if(front == -1){
                cout << "Queue is empty" << endl;
                return NULL;
            }
            Node* Aux = &Q[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else{
                front++;
            }
            return Aux;
        }
        void Display(){
            if(IsEmpty()){
                cout << "Empty Queue" << endl;
            }
            else{
                cout << endl << "Front -> ";
                for(int i = front; i <= rear; i++){
                    cout << Q[i].value << " ";
                }
                cout << " <- Rear" << endl << endl;
            }
        }
        bool IsEmpty(){
            if (front == -1)
            {
                return true;
            }
            return false;
        }
};

int main(){
    Queue C(3);
    int x;
    for(int i = 0; i < 4 ; i++){
        cout << "Enter Value: ";
        cin >> x;
        C.Enqueue(x);
    }
    C.Display();
    while(!C.IsEmpty()){
        cout << C.Dequeue()->value<< " " << endl;
    }
    return 0;
}