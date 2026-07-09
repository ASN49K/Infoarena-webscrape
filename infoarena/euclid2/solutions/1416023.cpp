#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a,b,c;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> a >> b;
    while(a>0){
        c=a;
        a=b%a;
        b=c;
    }
    out << b;
}
