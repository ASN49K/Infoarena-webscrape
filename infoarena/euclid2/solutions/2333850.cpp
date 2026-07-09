#include <iostream>
#include<fstream>
using namespace std;
ifstream fin ("euclidein.txt");
ofstream fout ("euclidout.txt");
int main()
{

 int t,x,y,i=0;
 fin>>t;
 while(i!=t)
 {
     fin>>x>>y;

     while(x!=y)
     {
         if(x>y)
            x=x-y;
         else
            y=y-x;

     }
     fout<<x<<"\n";
     i++;
 }

    return 0;
}
