#include <iostream>
#include<fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{

 int t,x,y,i=0;
 fin>>t;
 while(i!=t)
 {
     fin>>x>>y;
     if(y>x)
        swap(x,y);
     while(y!=0)
     {
      int r=x%y;
      x=y;
      y=r;

     }
     fout<<x<<"\n";
     i++;
 }

    return 0;
}
