#include <iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int i,j,a,b,r,x=-1,k,n,v[100000];
    cin>>n;
    for(k=1;k<=n;k++)
    {
    cin>>i;
    cin>>j;
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
   cout<<b;
   cout<< '\n';
    }


   return 0;
}




