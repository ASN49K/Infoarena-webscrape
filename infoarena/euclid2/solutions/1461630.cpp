#include <iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    long long i,j,a,b,r,x=-1,k,n,v[100000];
    in>>n;
    for(k=1;k<=n;k++)
    {


    in>>i;
    in>>j;
    if(i>j)
    {
        a=i;
        b=j;
    }
    else
    {
        a=j;
        b=i;
    }
    r=a%b;
   while(r)
   {
       a=b;
       b=r;
       r=a%b;
   }
   x++;
   v[x]=b;
    }
    for(i=0;i<=x;i++)
    {
        out<<v[i];
        out<<endl;

    }

   return 0;
}




