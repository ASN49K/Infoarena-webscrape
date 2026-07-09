#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a;
int b;
int cmmdc(int a,int b)
{
          int r=a%b;
          if (r==0) return b;
          else return cmmdc(b,r); 
          }


int main()
{
    f>>a>>b;
    g<<cmmdc(a,b);
    f.close();
    g.close();
    return 0;
    }
