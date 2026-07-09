#include<fstream.h>
int a,b;
int cmmdc(int a,int b)
{
 if(a==0) return b;
 return cmmdc(b%a,a);
}
int main()
{
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>a>>b;
 g<<cmmdc(a,b)<<endl;
 g.close();
}