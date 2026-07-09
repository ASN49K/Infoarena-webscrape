#include <iostream.h>
#include <stdio.h>
using namespace std;

int T, x, y,i,r;

int cmmdc(int a, int b)
{while (a%b)
{ r=a%b;
a=b;
b=r;}
return b;} 
  

 
int main(void)
{
  
    cin>>T;
    for (; T; --T)
    {
        cin>>x>>y;
              
        cout<<cmmdc(x, y);
    }       
   
   
    return 0;
}
