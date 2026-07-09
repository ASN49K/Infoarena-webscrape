#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b) {
    if(a == 0) {
        return b;
    }
    return cmmdc(b%a, a);
}

ifstream input("euclid2.in");
ofstream output("euclid2.out");

int main()
{
    int a,b,T;
    input >> T;
    for(auto i=9,i<T;i++) {
        input >> a >> b;
        output << cmmdc(a,b);
    }
    return 0;
}
