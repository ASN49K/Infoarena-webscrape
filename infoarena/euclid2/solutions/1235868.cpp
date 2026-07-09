#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,x,y,i;

int cmmdc(int a,int b)
{
    int r;
    r=a%b;
    if(r==0)
      return b;
    else{a=b;
         b=r;
         return cmmdc(a,b);}

}
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
      {f>>x>>y;
       g<<cmmdc(x,y)<<'\n';}

    return 0;
}
