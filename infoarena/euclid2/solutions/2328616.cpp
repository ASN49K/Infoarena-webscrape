#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long n;
int cmmdc(int a,int b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}
int main ()
{
 fin>>n;
 int i=1
 while(i!=n)
 {

     int a,b;
     fin>>a>>b;
     fout<<cmmdc(a,b);
     fout<<endl;
     i++;
 }
 return 0;



}
