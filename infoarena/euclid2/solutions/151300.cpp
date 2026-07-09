#include<iostream>
#include<stdio.h>
using namespace std;
long long a,b,t;
int main()
{   freopen("euclid2.in","r",stdin);
    cin>>a>>b;
    fclose(stdin);
    while (b != 0)
         {
         t=b;
         b=a%b
         a=t;
         }
    freopen("euclid2.out","w",stdout);
    cout<<a;
    fclose(stdout);
    return 0;
}
