#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b,i;

int main()
{ f>>T;
  for(i=1;i<=T;i++)
  {
      f>>a>>b;
      while(a!=b)
       {if(a>b) a=a-b;
       else b=b-a;
       }
    g<<a<<'\n';
  }
    return 0;
}
