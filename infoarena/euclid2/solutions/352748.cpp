#include<iostream.h>
#include<fstream.h>

int cmmdc(int a, int b)
{ 
    while (a!=b)
    { 
          if (a>b)
          a=a-b;
          else
          b=b-a;
    }
return 1;
}


int main ()
{
    int n,a,b,i;
    
    fstream f("euclid2.in");
    ofstream g("euclid2.out");
    
    f>>n;
    
    for (i=0; i<=n; i++)
    { 
        f>>a;
        f>>b;
        
        if (cmmdc)
        g<<a;
        g<<endl;
    }

return 0;
}
