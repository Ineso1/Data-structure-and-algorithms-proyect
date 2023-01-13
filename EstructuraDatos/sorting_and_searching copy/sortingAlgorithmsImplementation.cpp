#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class MyDataStructure:public SortingAlgorithms, public SearchAlgorithms{
    private:
        vector<int> unsortedList;
        int numElements;

    public:
        MyDataStructure();
        MyDataStructure(int);
        void generateList();
        void printList();
};

MyDataStructure::MyDataStructure():SortingAlgorithms(),SearchAlgorithms(){
    this->numElements = 0;
}

MyDataStructure::MyDataStructure(int numElements){
    this->numElements = numElements;
    this->generateList();
}

void MyDataStructure::generateList(){
    for (int i = 0; i < this->numElements; i++)
    {
        int n = rand() % 100;
        this->unsortedList.push_back(n);
    }    
}

void MyDataStructure::printList(){
    cout<<endl;
    for (int i = 0; i < this->numElements; i++)
    {
        cout<<this->unsortedList[i]<<"\t";
    }   
}

class SortingAlgorithms
{
public:
    SortingAlgorithms();
    void swap(int&, int&);
    void exchangeSort();    //Funcion Exchange Sort
    void bubbleSort();      //Funcion Bubble Sort
    void mergeSort();       
    void quickSort();       //Funcion Quick Sort
    void merge(vector<int>&, int, int, int);
    void recursionMergeSort(vector<int>&, int, int);        //Funcion Merge Sort
};

//Funciones de ordenamiento
//  Exchange
//  Bubble sort
// MergeSort
// QuickSort


void SortingAlgorithms::swap(int &a, int&b){
    int aux = a;
    a = b;
    b = aux;
}

void SortingAlgorithms::exchangeSort(){
    for(int i = this->numElements; i > 0; i--){
        for(int j = 1; j < i; j++){
            if (this->unsortedList[j-1] > this->unsortedList[j])
            {
                this->swap(this->unsortedList[j-1], this->unsortedList[j]);
            }
        }
    }
}

void SortingAlgorithms::bubbleSort(){
    for (int i = 0; i < this->numElements; i++)
    {
        for (int j = i; j < (this->numElements); j++)
        {
            if (this->unsortedList[i] > this->unsortedList[j])
            {
                this->swap(this->unsortedList[j], this->unsortedList[i]);
            }
        }   
    } 
}


void SortingAlgorithms::merge(vector<int> &A,int l, int m,int r)     
{

    int n1,n2,i,j,k;
    n1=m-l+1;
    n2=r-m;             
    vector<int> L;
    vector<int> R;
    for(i=0;i<n1;i++)
    {
        L[i]=A[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=A[m+j+1];
    }
    i=0, j=0, k=0;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i++];
            i++;
        }
        else
        {
            A[k]=R[j++];
            j++;
        }
    }
    while(i<n1)             
    {
        A[k++]=L[i++];
    }
    while(j<n2)
    {
        A[k++]=R[j++];
    }
}

void SortingAlgorithms::recursionMergeSort(vector<int>& A,int l,int r)    
{
    int m;                                
    if(l<r)
    {
        m=(l+r)/2;
        recursionMergeSort(A,l,m);
        recursionMergeSort(A,m+1,r);
        merge(A,l,m,r);
    }
}

void SortingAlgorithms::mergeSort(){
    this->recursionMergeSort(this->unsortedList, 0, this->numElements - 1);
}

class SearchAlgorithms
{
public:
    SearchAlgorithms();
    binarySearch();
};

int main(){    
    MyDataStructure lista1 = MyDataStructure(10);
    lista1.printList();
    return 0;

}