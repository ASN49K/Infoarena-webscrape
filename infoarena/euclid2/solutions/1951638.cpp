#include <iostream>
#include <limits.h>
using namespace std;
///V2) Calculaţi produsul elementelor din vector , cu metoda D&I.
///V3) Calculaţi suma elementelor impare cu indici pari din vector, cu metoda D&I.
///V4) Determinaţi valoarea minimă din vector , cu metoda D&I.
///V6) Determinaţi minimul dintre elementele pare din vector, cu metoda D&I.
///V7) Determinaţi numărul elementelor pare cu indici impari din vector , cu metoda D&I.
///V8) Determinaţi numărul elementelor prime din vector, cu metoda D&I.
int p(int a[], int s, int d)
{
    if(s==d) return a[s];
    else
    {
       return p(a,s,(s+d)/2)*p(a,(s+d)/2+1,d);
    }
}
int suma(int a[], int s, int d)
{
    if(s==d)
    {
        if(a[s]%2!=0 && s%2==0)return a[s];
        else return 0;
    }
    else
    {
        return suma(a,s,(s+d)/2)+suma(a,(s+d)/2+1,d);
    }
}
int min1(int a[], int s, int d)
{   int x,y;
    if(s==d)return a[s];
    else
    {   x=min1(a,s,(s+d)/2);
        y=min1(a,(s+d)/2+1,d);
        if(x<y) return x;
        else return y;
    }

}
void minp(int a[], int s, int d, int &min)
{   int x,y;
    if(s==d && a[s]%2==0)min=a[s];
    if(s!=d)
    {
        minp(a,s,(s+d)/2,min);
        x=min;
        minp(a,(s+d)/2+1,d,min);
        y=min;
        if(x<y)min=x;
        else min=y;
    }
}
void cont(int a[], int s, int d, int &c)
{
    if(s==d && s%2!=0 && a[s]%2==0)c++;
    if(s!=d)
    {
        cont(a,s,(s+d)/2,c);
        cont(a,(s+d)/2+1,d,c);
    }
}
int prim(int n, int d)
{
    if(n<2 || (n>2 && n%2==0))return 0;
    if(d*d<=n)
      {
          if(n%d==0)return 0;
          return prim(n,d+2);
      }
    return 1;

}
void nrp(int a[], int s, int d, int &c)
{
    if(s==d && prim(a[s],3))c++;
    if(s!=d)
    {
        nrp(a,s,(s+d)/2,c);
        nrp(a,(s+d)/2+1,d,c);
    }
}
int main()
{   int a[100], n, c=0, min=INT_MAX; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<"v2)"<<p(a,1,n);
    cout<<endl<<"v3)"<<suma(a,1,n);
    cout<<endl<<"v4)"<<min1(a,1,n);
    cout<<endl<<"v6)";
    minp(a,1,n,min);
    cout<<min;
    cout<<endl<<"v7)";
    cont(a,1,n,c);
    cout<<c;
    cout<<endl<<"v8)";
    c=0;
    nrp(a,1,n,c); cout<<c;


    return 0;
}
