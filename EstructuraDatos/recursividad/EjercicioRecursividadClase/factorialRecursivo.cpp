#include <iostream>
using namespace std;

int fibonacci(int i){
    if (i <= 2) return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
} 

int factorial(int i){
    if (i <= 0){
        return 1;
    }
    return i * factorial(i - 1);
}

int main(){
    cout << factorial(3)<<endl;
    cout << fibonacci(8)<<endl;
}