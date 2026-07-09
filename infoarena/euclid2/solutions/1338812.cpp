#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int prim(int a,int b){
    while(a!=b){
        if(a>b){
            a-=b;
        }
        if(b>a){
            b-=a;
        }
    }
    return a;
}

struct verif
{
    int nr1;
    int nr2;
};

verif v[1000000];

int main()
{

    int n,nr1,nr2;
    in>>n;
    for(int i=1;i<=n;i++){
        in>>v[i].nr1;
        in>>v[i].nr2;
        out<< prim(v[i].nr1,v[i].nr2)<<endl;
    }
    return 0;
}
