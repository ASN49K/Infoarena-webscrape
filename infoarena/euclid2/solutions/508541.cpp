#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i,a,b;
int cmmdc(int a,int b)
    {while(a!=b)if(a>b)a-=b;else b-=a;
    return a;
    }
int main()
    {f>>t;
    for(i=1;i<=t;i++){f>>a>>b;
		      g<<cmmdc(a,b)<<'\n';
		      }
    g.close();
    f.close();
    return 0;
    }