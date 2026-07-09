#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n;

int euclid(int a, int b){
    if(!b) return a;
    return euclid(b,a%b);
}

int main()
{
    in>>n;int a,b;
    for (int i=n;i>0;i--){
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
    }

    return 0;
}
