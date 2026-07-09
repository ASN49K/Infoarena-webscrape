#include <iostream>
#include <fstream>
int n,a,b,i,d;
using namespace std;

int cmmdc(int x,int y){
    //prin scaderi
    /*if(x==y)
        return x;
    else if(x>y){
        cmmdc(y,x-y);
    }
    else if(y>x)
        cmmdc(x,y-x);*/
    //prin impartiri
    if(x>=y){
        if(x%y==0)
            return y;
        else
            cmmdc(y,x%y);
    }
    else if(y>=x){
        if(y%x==0)
            return x;
        else
            cmmdc(x,y%x);
    }
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++){
        f>>a>>b;
        d=cmmdc(a,b);
        g<<d<<'\n';
    }
    return 0;
}
