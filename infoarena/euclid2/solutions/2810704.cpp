#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b){
        while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int i,t,a,b;
    fin>>t;
    for(i=1;i<=t;i++){
        fin>>a>>b;

    fout<<cmmdc(a,b)<< endl;
    }
    return 0;
}
