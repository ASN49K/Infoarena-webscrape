#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
        if (!b) return a;

    return gcd(b, a % b);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    int x;
    int y;
    //long long rest;
    fin>>T;
    for(int i=0;i<T;i++){
        fin>>x;
        fin>>y;

        fout<<gcd(x,y)<<"/n";
    }
}
