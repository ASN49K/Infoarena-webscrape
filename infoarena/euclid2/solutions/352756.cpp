#include<iostream.h>
#include<fstream.h>

int main ()
{
    int T,a,b,i;
    
    fstream f("euclid2.in");
    ofstream g("euclid2.out");
    
    f>>T;
    
    for (i=0; i<=T; i++)
    { 
        f>>a;
        f>>b;
        
        while (a!=b)
       { if (a>b)
        a=a-b;
        else
        b=b-a;
        } 
        
        g<<a;
        g<<endl;
    }
return 0;
}
