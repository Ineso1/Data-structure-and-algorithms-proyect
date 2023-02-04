#include <iostream>
using namespace std;

class Solution {
public:


    string convert(string s, int numRows) {
        string **matrix;
        matrix = new string*[s.length()];
        for(int i=0; i< s.length(); i++){
            matrix[i] = new string[numRows];
            for(int j=0; j<numRows; j++){
                // matrix[i][j] = "";
                cout<<".";
            }
            cout<<endl;
        }
        return "";
    }
};


int main(){
    string s = "PAYPALISHIRING";
    int numRows = 3;
    Solution sol;
    sol.convert(s, numRows);
    return 0;
}