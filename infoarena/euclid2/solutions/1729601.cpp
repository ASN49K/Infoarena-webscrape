#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
 
int main()
{
    int t,a,b,d,x;
 
    fin>>t;
    for(int i=1; i<=t; i++){
        fin>>a;
        fin>>b;
 
    if(a<b){
        x=a;
        a=b;
        b=x;
    }

    while(b!=0){
        d=a%b;
        a=b;
        b=d;
        }
 
    fout<<a<<'\n';
    }
 
    return 0;
}