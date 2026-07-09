#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


long cmmdc(long x, long y){
if(x>=y){
    if(x%y==0)return y;
    else {x=x%y;cmmdc(y,x);}
}else if(y%x==0)return x;
    else{y=y%x;cmmdc(x,y);}

}

int main()
{
    long a,x,y;
    fin>>a;
    while(a){
        fin>>x>>y;
        fout<<cmmdc(x,y)<<"\n";a--;
    }

    return 0;
}
