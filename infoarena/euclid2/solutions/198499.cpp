
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
int main(void)
{
 fstream f("euclid2.in", ios::in);
 //fstream g("euclid2.out", ios::out);
 int T, a[100], b[100],i;
 f>>T;i=T;
 while(T){f>>a[T];
 f>>b[T];
 //g<<cmmdc(a,b)<<endl;
 T--;}
 f.close();
 fstream g("euclid2.out", ios::out);
 while(i){g<<cmmdc(a[i],b[i])<<endl;}
 g.close();
 return 0;
}

