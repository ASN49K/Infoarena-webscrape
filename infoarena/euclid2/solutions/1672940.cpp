#include <iostream>
#include <fstream>

using namespace std;

ifstream q("joc.in");
ofstream w("joc.out");

int Map[1010][1010];

void maxim(int Map[][1010],int &l,int &c,int &max)
{
    int i,j,n,m;
    max=0;
    for(i=1;i<=l;i++)
        for(j=1;j<=c;j++)
            if(max<Map[i][j]) {max=Map[i][j];n=i;m=j;}
    l=n;
    c=m;
    Map[n][m]=0;
}

int main()
{int l,c,i,j,max,cine=1,a=0,b=0,d,t1,t2,x,y;

    q>>l>>c;
    for(i=1;i<=l;i++)
        for(j=1;j<=c;j++)
            q>>Map[i][j];
    d=Map[1][1];
    maxim(Map,l,c,max);
    a=max;
    x=l;
    y=c;
    while(!(l==1 && c==1))
    {
        maxim(Map,l,c,max);
        t1=max;
        maxim(Map,l,c,max);
        t2=max;
        if(t1-t2>d)
        {
            if(cine==0) {a+=t1-t2;cine=1;}
            else {b+=t1-t2;cine=0;}
        }
        else
        {
            if(cine==0) {a+=d;break;}
            else {b+=d;break;}
        }
    }
    w<<a-b<<" "<<x<<" "<<y;




    return 0;
}
