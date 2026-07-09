#include<iostream>
#include<fstream>

int func(int a, int b);

using namespace std;
int main() {
 fstream vin("euclid2.in");
 ofstream duc("euclid2.out");
 int t,m,n,d;
 vin>>t;
 for (int i=1; i<=t; i++) 
   {  vin>>m>>n; d=func(m,n);
   duc<<d<<"\n";
          }
  vin.close();  
  duc.close(); 
return(0);    
    }

int func(int a,int b)
{
  if (a%b==0) return(b); else return(func(b, a%b));  
    }
