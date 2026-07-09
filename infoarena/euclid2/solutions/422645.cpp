#include<iostream.h>
#include<fstream.h>
int a,b,d,n,i;
main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
       f>>n;
       while(n--){
       f>>a;
       f>>b;
       i++;
                do {d=a%b;
                    a=b;
                    b=d;
                    } while (d);
       g<<a<<endl;
         }
       f.close();
       g.close();
             
       }               
