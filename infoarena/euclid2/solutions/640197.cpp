#include<fstream>

using namespace std;

int main()
{
    int a,b,n,i,t,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a;
        f>>b;

      while( b != 0)
     {

       t=b;
       b=a%b;
       a=t;
      }


        g<<a<<endl;
    }
    return 0;
}
