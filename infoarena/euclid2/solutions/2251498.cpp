
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
if (b==0) return a;
else return euclid(b,a%b);

}
int main()
{
  int T,a,b;
  f>>T;
  for(int i=1;i<=T;i++)
  {
    f>>a>>b;
    g<<euclid(a,b)<<endl;
  }
}
