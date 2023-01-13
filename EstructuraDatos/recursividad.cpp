#include <iostream>
using namespace std;

int fibonacci(int i){
    if (i <= 2) return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
} 


int main(){
    cout << fibonacci(8);
}