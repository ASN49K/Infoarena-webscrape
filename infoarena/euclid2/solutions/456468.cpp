#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int t,i,a,b,r;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
 
    fin>>t;
   
   for(i=1;i<=t;i++)
  {  fin>>a;
    fin>>b;
    ofstream gout("euclid2.out");
    do
    { r=a%b;
       a=b;
       b=r;
       }
       while(r!=0);
       fout<<a;
       }
       
       fin.close();
       fout.close();
       return 0;
       }
    
