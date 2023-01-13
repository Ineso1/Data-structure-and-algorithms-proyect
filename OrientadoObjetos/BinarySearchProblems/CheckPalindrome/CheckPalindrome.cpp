#include <iostream>
using namespace std;

class Solution
{
public:
    Solution(){};
    bool solve(string s){
        for (int i = s.length()-1, int indexS = 0; i >= 0 && i != indexS; i--, indexS++)
        {
            if (s[i] != s[indexS])
            {
                return false;
            }
        }
        return true;
    }
};

/*
class Solution
{
public:
    Solution(){};
    bool solve(string s){
        string reverse = "";
        for (int i = s.length()-1; i >= 0; i--)
        {
            reverse += s[i];
        }
        cout<<reverse;
        if (s == reverse)
        {
            return true;
        }
        
        return false;
    }
};
*/


/*
//Codigo en python
class Solution:
    def solve(self, s):
        if(s==s[::-1]):
            return True
        return False
*/

int main(){
    string s = "racecar";
    Solution sol;
    cout << sol.solve(s);
    return 0;
}

