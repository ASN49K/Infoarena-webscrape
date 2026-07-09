#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmmdc.in");
ofstream out("cmmdc.out");

int main()
{   short int a,b;
     in>>a;
     in>>b;
     int r;
     while(b)
     {     r=a%b;
           a=b;
           b=r;
     }
     if(a==1)
          out<<0;
     else
          out<<a;
     return 0;
}
