#include <iostream>
#include <limits.h>
#include <climits>
using namespace std;

struct Node
{
    int value;
    int priority;
};


class PriorQueue{
    private:
    Node *PQ;
    int N, NumNodes;
    public:
    PriorQueue(int size){
        N = size;
        PQ = new Node[size];
        NumNodes = -1;
    };

    ~PriorQueue(){
        delete[] PQ;
    };

    void Enqueue(int value, int priority){
        if(NumNodes == N-1){
            cout<<"Priority Queue is full"<<endl;
            return;
        }
        NumNodes++;
        PQ[NumNodes].value = value;
        PQ[NumNodes].priority = priority;
    };

    Node *Dequeue(){
        if(NumNodes == -1){
            cout<<"Priority Queue is empty"<<endl;

            return NULL;
        }
        int ind = Peek();
        Node *Aux = &PQ[ind];
        for (int i = ind; i < NumNodes; i++)
        {
            PQ[i] = PQ[i+1];
        }
        NumNodes--;
        return Aux;
    };
    int Peek(){
        int highestPriority = INT_MIN;
        int ind = -1;
        for (int i = 0; i <= 0; i++){
            if(highestPriority < PQ[i].priority){
                highestPriority = PQ[i].priority;
                ind = i;
            }
            else if(highestPriority == PQ[i].priority && PQ[i].value > PQ[ind].value){
                highestPriority = PQ[i].priority;
                ind = i;
            }
        }
        return ind;
    };
    void Display(int idx){
        cout<< PQ[idx].value<<endl<<endl;
    };
    void Display(){
        cout<< "Elements: ";
        for (int i = 0; i < NumNodes; i++)
        {
            cout<< PQ[i].value<<" ";
        }
        cout << endl << endl;
    };
};

int main(){
    PriorQueue P(5);
    P.Enqueue(10,2);
    P.Enqueue(14,4);
    P.Enqueue(16,4);
    P.Enqueue(12,3);
    P.Display();
    int indx = P.Peek();
    cout << "Higher priority element: ";
    P.Display(indx);
    P.Dequeue();
    P.Display();
    
    indx = P.Peek();
    cout << "Higher priority element: ";
    P.Display(indx);
    P.Dequeue();
    P.Display();
    indx = P.Peek();
    
    cout << "Higher priority element: ";
    P.Display(indx);
    P.Dequeue();
    P.Display();



    return 0;
}