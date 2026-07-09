#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a,b;
    ifstream fin ("cmmdc.in");
    ofstream fout ("cmmdc.out");
    fin>>a;
    fin>>b;

   while(a!=b)
   {
    if(a>b)
    {a=a-b;
    }
    else b=b-a;

   }
   if (b==1)
   {
       b=0;
   }
   fout<<b;
}
