
#include <iostream.h>
#include <fstream.h>
int cmmdc(int a,int b)
{
 if (a==0) return b;
 else if(b==0) return a;
 else return cmmdc(b,a%b);
}
int main(int argc, char** argv)
{
 fstream f("euclid2.in", ios::in);
 fstream g("euclid2.out", ios::out);
 int T, a, b;
 f>>T;
 while(T){f>>a;
 f>>b;
 g<<cmmdc(a,b)<<endl;
 T--;}
 g.close();
 f.close();
 return 0;
}

