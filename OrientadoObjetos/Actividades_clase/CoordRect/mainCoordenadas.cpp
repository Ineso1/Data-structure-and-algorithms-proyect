#include <iostream>
#include "CoordRect.h"
#include "CoordPolar.h"
using namespace std;

int main(){
    CoordRect c1(2,3);
    CoordRect c2(4,7);
    CoordPolar p1(4,20);
    CoordPolar p2(5,10);
    CoordRect suma=c1+c2;
    CoordRect suma2=c1 + p1;
    CoordPolar multP1 = p1 * p2;
    cout << suma << endl;
    cout << suma2 <<endl;
    cout << multP1 << endl;
    return 0;
}