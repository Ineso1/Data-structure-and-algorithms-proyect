#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

void ExchangeSort(){
    int lista[] = {5,6,7,2,3,4,9,1,8};
    for(int i = sizeof(lista)/sizeof(int); i > 0; i--){
        for(int j = 1; j < i; j++){
            if (lista[j-1] > lista[j])
            {
                swap(lista[j-1], lista[j]);
            }
        }
    }
    for (int i = 0; i < sizeof(lista)/sizeof(int) ; i++)
    {
        cout << lista[i];
    }
    
}

void BubbleSort(){
    int lista[] = {5,6,7,2,3,4,9,1,8};
    for (int i = 0; i < sizeof(lista)/sizeof(int); i++)
    {
        for (int j = i; j < (sizeof(lista)/sizeof(int)); j++)
        {
            if (lista[i] > lista[j])
            {
                swap(lista[j], lista[i]);
            }
        }   
    }
    for (int i = 0; i < sizeof(lista)/sizeof(int) ; i++)
    {
        cout << lista[i];
    }
    
}


void Merge(int A[],int p, int q,int r)     
{

    int n1,n2,i,j,k; 
    n1=q-p+1;
    n2=r-q;             
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
    }
    i=0,j=0;
    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];
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
void MergeSort(int A[],int p,int r)    
{
    int q;                                
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main(){
    ExchangeSort();
    cout << endl;
    BubbleSort();

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
 
    MergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);

    return 0;
}