#include<iostream.h>
#include<fstream.h>
int main()
{
    int j,i,a,b,r,c;
   ifstream f("euclid2.in");
   ofstream g("euclid.out"); 
   f>>i;
   for(j=1;j<=i;j++)
   {f>>a;
   f>>b;

    while(a%b!=0)
    {
                 r=a%b;
                 a=b;
                 b=r;
    }
    g <<b;
    g<<"\n";
}   

    
return 0;    

}
