#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    long t,i,a,b,r;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
 
    fin>>t;
   
   for(i=1;i<=t;i++)
  {  fin>>a;
    fin>>b;
  
    do
    { r=a%b;
       a=b;
       b=r;
       }
       while(r!=0);
       fout<<a<<endl;
       }
       
       fin.close();
       fout.close();
       return 0;
       }
    
