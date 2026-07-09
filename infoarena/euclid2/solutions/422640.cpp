#include<iostream.h>
#include<fstream.h>
long a,b,d,n,i;
main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
      f>>n;
      while(i<n)
      {f>>a;
       f>>b;
       i++;
       while(b!=0) {d=a%b;
                    a=b;
                    b=d;
                    }
       g<<a<<endl;
       }
       f.close();
       g.close();
             
       }               
