#include <fstream>


using namespace std;

int cmmdc(int k,int l)
{int r;
    if(l==0)return k;
    else {while(l!=0){r=k%l;k=l;l=r;}
    return k;}
}
int main()
{int a,b,t,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(i=1;i<=t;i++){f>>a>>b;
g<<cmmdc(a,b)<<endl;}
    return 0;
}




