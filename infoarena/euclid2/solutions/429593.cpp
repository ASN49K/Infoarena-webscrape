#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
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
freopen("euclid2.out","w",stdout);
       f>>n;
       while(i<n)
	   {	
			f>>x>>y;
            i++;
			printf("%d\n",euclid(x,y));
			//cout<< euclid( x,y)<<endl;	   
       //           g<<euclid(x,y)<<endl;
                   
         }
       f.close();
       
             
       }               
