//
//  main.cpp


#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b){
    if (b==0) return a;
    return cmmdc(b, b%a);
}

int a,b,n;

int main()
{
    in >> n;
    for (int i=1; i<=n; i++){
        in >> a >> b;
        out << cmmdc(a,b) << "\n";
    }
    return 0;
}

