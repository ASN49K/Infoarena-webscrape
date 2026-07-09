#include<iostream>
#include<fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out("euclid2.out");
int main ()
{
     int n,i,r,a,b;
     in>>n;
     for (i=1;i<=n;i++)
     {  
        in>>a; in>>b;
        
        while (b!=0)
        {
        	r=a%b;
        	a=b;
        	b=r;
        }
     	
     	out<<a<<" ";
     }

     
in.close();
out.close();
return 0;
}
