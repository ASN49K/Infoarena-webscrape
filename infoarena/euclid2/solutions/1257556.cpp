#include <iostream>
#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
     if(b==0) return a;
     return cmmdc(b,a%b);
}
int main()
{ int n, a,b;
 ifstream f("euclid2.in");
 f>>n;
 ofstream g("euclid2.out");
 for(int i=0;i<n;i++)
 {
     f>>a>>b;
     g<<cmmdc(a,b)<<endl;
 }
 f.close();
 g.close();
 return 0;
}
