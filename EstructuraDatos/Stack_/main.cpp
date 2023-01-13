#include <iostream>
using namespace std;


struct Node{
    int num;
};

class Stack{
    private:
        int N, Top;
        Node *st;
    public:
        Stack(int size){
            Top = -1;
            N = size;
            st = new struct Node[N];
        }
        ~Stack(){
            cout<<"Destructor: Erase Stack" <<endl;
            delete[] st;
        }
        void Push(int NUM){
            if(Top == N-1){ 
                cout << "The stack is full (Overflow)." << endl;
                return;
            }
            Top++;
            st[Top].num = NUM;
        }
        Node* Pop(){
            if(Top < 0){ 
                cout << "The stack is empty (Underflow)." << endl;
                return NULL;
            }
            Top--;
            return &st[Top + 1];
        }
        bool IsEmpty(){
            if(Top < 0){
                return true;
            }
            return false;
        }
        int *Peek(){
            if(Top < 0){
                return NULL;
            }
            return &(st[Top].num);
        }
};

int main(){
    int size;
    cout<< "Insert size of the stack: ";
    cin >> size;
    Stack P(size);
    int x;
    for(int i = 0; i < size; i++){
        cout << "Enter value: ";
        cin >> x;
        P.Push(x);
    }
    P.Push(100);

    int *v;
    v = P.Peek();
    cout << "The value at top is: " << *v << endl;

    while (!P.IsEmpty())
    {
        cout << P.Pop()->num << " " << endl;
    }
    return 0;
}