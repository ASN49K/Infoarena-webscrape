#include <iostream.h>
#include <stdio.h>
using namespace std;

int T, x, y,i,r;

inline int cmmdc(int a, int b)
{while (a%b)
{ r=a%b;
a=b;
b=r;}
return b;} 
  

 
int main(void)
{freopen("euclid2.in", "r", stdin);
   freopen("euclid2.out", "w", stdout);
  
    cin>>T;
    for (; T; --T)
    {
        cin>>x>>y;
              
        cout<<cmmdc(x, y)<<"\n";
    }       
   
   
    return 0;
}
