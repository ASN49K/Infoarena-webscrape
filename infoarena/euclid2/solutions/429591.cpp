#include<iostream.h>
#include<fstream.h>
int x,y,n;

int euclid(int a,int b){
    int d;
    while (b)    {  d=a%b;
                    a=b;
                    b=d;
                    }
                    return a;
                    }
main()
{ int i;
ifstream f("euclid2.in");
//ofstream g("euclid2.out");
freopen("eudlicd2.out","w",stdout);
       f>>n;
       while(i<n)
	   {	
			f>>x>>y;
            i++;
			
			cout<< euclid( x,y)<<endl;	   
       //           g<<euclid(x,y)<<endl;
                   
         }
       f.close();
       
             
       }               
