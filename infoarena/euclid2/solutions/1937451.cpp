#include <iostream>
#include <fstream>

using namespace std;

long lnko(long a, long b) {
    if(a==1) {
        return 0;
    }
    else {
        if(a==b) {
            return a;
        }
    else {
    if(a<b) {
        return lnko(a,b - a);
    }
    else {
        return lnko(a - b,b);
    }
    }
}
}

int main()
{
    long a; long b;
    ifstream be("cmmdc.in");
    ofstream ki("cmmdc.out");
    be >> a; be >> b;
    ki << lnko(a,b);
    return 0;
}
