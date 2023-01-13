/*
Programming of data structures and fundamental algorithms
Research algorithms
Ines Alejandro Garcia Mosqueda
A00834571
28/08/2022
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


//Clase de algoritmos para ordenamiento
class MyDataStructure
{
private:
    vector<int> unsortedList;
    int numElements;
    void merge(vector<int>&, int, int, int);                //Funcion Merge
    void recursionMergeSort(vector<int>&, int, int);        //Funcion recursiva Merge Sort
public:
    MyDataStructure();
    MyDataStructure(int);
    void generateList();
    void printList();
    void swap(int&, int&);          //Intercambio de posiciones
    void exchangeSort();            //Funcion Exchange Sort
    void bubbleSort();              //Funcion Bubble Sort
    void mergeSort();               //LLamar la funcion de ordenamiento por Merge con datos del objeto
    void quickSort();               //Funcion Quick Sort
    int sequentialSearch(int);      //Funcion Sequential Search
    int binarySearch(int);          //Funcion Binaty Search
};



//Funciones para inicializar lista desordenada dado un numero de elementos

MyDataStructure::MyDataStructure(){
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

/*...........................................*/
//Funciones de ordenamiento
//  Exchange Sort
//  Bubble Sort
//  Merge Sort
//  Quick Sort

void MyDataStructure::swap(int &a, int&b){
    int aux = a;
    a = b;
    b = aux;
}

/*
Exchange Sort
Complexity O(n^2)
Space complexity O(1)
*/
void MyDataStructure::exchangeSort(){
    for(int i = this->numElements; i > 0; i--){
        for(int j = 1; j < i; j++){
            if (this->unsortedList[j-1] > this->unsortedList[j])
            {
                this->swap(this->unsortedList[j-1], this->unsortedList[j]);
            }
        }
    }
}

/*
Bubble Sort
Complexity O(n^2)
Space complexity O(1)
*/
void MyDataStructure::bubbleSort(){
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

/*
Merge Sort
Complexity O(nLog(n))
Space complexity O(n)
*/
void MyDataStructure::merge(vector<int> &A,int l, int m,int r)     
{
    int n1,n2,i,j,k;
    n1=m-l+1;
    n2=r-m;             
    vector<int> L(n1);
    vector<int> R(n2);
    for(i=0;i<n1;i++)
    {
        L[i]=A[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=A[m+j+1];
    }
    i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)             
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}

void MyDataStructure::recursionMergeSort(vector<int> &A,int l,int r)    
{   
    int m;                                
    if(l<r)
    {
        m=(l+r)/2;
        this->recursionMergeSort(A,l,m);
        this->recursionMergeSort(A,m+1,r);
        this->merge(A,l,m,r);
    }
}

void MyDataStructure::mergeSort(){
    this->recursionMergeSort(this->unsortedList, 0, this->numElements - 1);
}

/*...........................................*/
//Funciones de busqueda
//  Sequential Search
//  Binary Search

/*
Sequential Search
Complexity O(log(n))
Space complexity O(1)
*/
int MyDataStructure::sequentialSearch(int k){
    for(int i=0; i<numElements; i++){
        if(k<=unsortedList[i]){
            if (k == unsortedList[i])
            {
                return i;
            }
            else{
                return -1;
            }
        }
    }
    return -1;
}

/*
Binary Search
Complexity O(log(n))
Space complexity O(1)
*/
int MyDataStructure::binarySearch(int k){
    int l = 0, r = numElements - 1, m;
    while (l<=r)
    {
        m = (l+r)/2;
        if (k==unsortedList[m])
        {
            return m;
        }
        else if (k<unsortedList[m])
        {
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    return -1;        
}

int sortingMenu(MyDataStructure &obj){
    int op;
    cout<<"\n\nOpcion de ordenamiento\n1. Merge\n2. Bubble\n3. Exchange"<<endl;
    try
    {
        cin>>op;
    }
    catch(const std::exception& e)
    {
        cout << "Opcion no valida\n";
        return -1;
    }
    
    switch (op)
    {
    case 1:
        cout<<"Ordenamineto por Merge Sort"<<endl;
        obj.mergeSort();
        break;
    case 2:
        cout<<"Ordenamineto por Bubble Sort"<<endl;
        obj.bubbleSort();
        break;
    case 3:
        cout<<"Ordenamineto por Exchange Sort"<<endl;
        obj.exchangeSort();
        break;
    default:
        cout << "Opcion no valida\n";
        return -1;
        break;
    }
    obj.printList();
    return 0;
}

int searchMenu(MyDataStructure &obj){
    int op, indice=-1, numSearch;
    cout<<"\n\nOpcion de busqueda\n1. Binary Search\n2. Sequential Search"<<endl;
    try
    {
        cin>>op;
        cout<<"\n\nNumero a buscar:\t";
        cin>>numSearch;
    }
    catch(const std::exception& e)
    {
        cout << "Opcion no valida\n";
        return -1;
    }
    switch (op)
    {
    case 1:
        cout<<"Busqueda Binaria"<<endl;
        indice  = obj.binarySearch(numSearch);
        break;
    case 2:
        cout<<"Busqueda Secuaencial"<<endl;
        indice = obj.sequentialSearch(numSearch);
        break;
    default:
        cout << "Opcion no valida\n";
        return -1;
        break;
    }
    cout<<"\nBusqueda del numero\t"<<numSearch<<"\nIndice:\t"<<indice<<endl;
    if (indice == -1)
    {
        return -2;
    }
    return indice;
}


/*...........................................*/
//Main
int main(){
    int numElements;
    cout<<"Se creara una lista de numero aleatorios a partir de un numero dado\n\nIntroduce la cantidad de elementos en la lista:\t";
    cin >> numElements;
    cout<<endl;
    MyDataStructure lista1 = MyDataStructure(numElements);
    lista1.printList();
    while (sortingMenu(lista1) == -1)
    {
        sortingMenu(lista1);
    }
    while (searchMenu(lista1) == -1)
    {
        searchMenu(lista1);
    }
    return 0;
}
//fin
