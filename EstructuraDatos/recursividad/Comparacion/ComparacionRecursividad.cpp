#include <iostream>
using namespace std;

int sumaRecursiva(int i){
    if (i<=0) return 0;
    return i + sumaRecursiva(i-1);
}

int sumaIterativa(int i){
    int sum = 0;
    while (i>=1){
        sum += i;
        i--;
    }
    return sum;
}

int sumaDirecta(int i){
    if(i >= 0){
    return i * (i+1)/2;
    }
    else{
        return 0;
    }
}

int main(){
    int num = 20;
    cout << sumaRecursiva(num) << endl;
    cout << sumaIterativa(num) << endl;
    cout << sumaDirecta(num) << endl;
    return 0;
}