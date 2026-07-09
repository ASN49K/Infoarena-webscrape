#include <iostream.h>
#include <stdio.h>
using namespace std;

int T, x, y,i;

int cmmdc(int a, int b)
{for (i=a;i<=a; i--)
  if (a%i==0&&b%i==0)
  return i;
}
 
int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
 
    cin>>T;
    for (; T; --T)
    {
        cin>>x>>y;
              
        cout<<cmmdc(x, y);
    }       
    
    return 0;
}
