#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> esteban (4, vector<int>(4,0));
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
            cout<<esteban[i][j]<< " ";
        cout<<endl;
        }
    return 0;
}