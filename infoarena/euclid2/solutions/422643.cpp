#include<iostream.h>
#include<fstream.h>
int a,b,d,n,i;
main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
      f>>n;
      for(i=1;i<=n;i++){
       f>>a;
       f>>b;
       
       while(b!=0) {d=a%b;
                    a=b;
                    b=d;
                    }
       g<<a<<endl;
       }
       f.close();
       g.close();
             
       }               
