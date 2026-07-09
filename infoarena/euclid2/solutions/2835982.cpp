#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int cm,int cn){

    int m = cm;
    int n = cn;
    while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int main(){
    int a,b,t;
    fin>>t;
    while(t){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
        t--;
    }
    return 0;
}
