#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b){
    while(b){
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n; in >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        in >> a >> b;
        out << cmmdc(a, b) << "\n";
    }
    return 0;
}

/*
3
12 42
21 7
9 10
*/
