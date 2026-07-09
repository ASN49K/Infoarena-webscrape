
#include <iostream.h>
#include <fstream.h>
int cmmdc(int a,int b)
{int r;
    while(b){
             r=a%b;
             a=b;
             b=r;    }
 return a;
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

