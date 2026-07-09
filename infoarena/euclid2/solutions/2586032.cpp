#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    long long a;
    long long b;
    long long rest;
    fin>>T;
    for(int i=0;i<T;i++){
        fin>>a;
        fin>>b;
        rest = a%b;
        while(rest!=0){
            a=b;
            b=rest;
            rest=a%b;
        }
        fout<<b<<endl;
    }
}
