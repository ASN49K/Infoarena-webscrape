#include <iostream>
#include <fstream>
using namespace std;
    ifstream fin("euclid2.in");
    ofstream gout("euclid2.out");
int nr, a, b,i;
/*int heuclid (int a, int b) {
    while (a!=b)
    if (a>b)
        a=a-b;
    else
        b=b-a;
    return a;
}*/
int main() {
    fin>>nr;
    for (i=1;i<=nr;i++)
    {
    fin>>a;
    fin>>b;
    while (a!=b)
    if (a>b)
        a=a-b;
    else
        b=b-a;
    gout<<a<<endl;
    }
}
