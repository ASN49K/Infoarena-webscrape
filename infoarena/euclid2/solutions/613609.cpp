#include <iostream>
#include <fstream.h>
using namespace std;
int main ()
{
    int a,b,rest; 
    ifstream fin("cmmdc.in");
fin>>a;
fin>>b;
fin.close();
    
while (a%b!=0)
{rest=a%b;
a=b;
b=rest;} 
     
     ofstream fout("cmmdc");
     if (b==1) fout<<0;
     else fout<<b;
     fout.close();
return 0;
}
