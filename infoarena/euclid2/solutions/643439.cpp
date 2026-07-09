#include<fstream>

using namespace std;

int main()
{
    int r,i,x,m,n,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    i=1;
    while(i<=n)
    {
    f>>a;
    f>>b;
    r=1;
    while(r)
    {r=a%b;
     a=b;
     b=r;
  }
    g<<a<<endl;
     i++;
   }
    f.close();
    g.close();
    return 0;
}
