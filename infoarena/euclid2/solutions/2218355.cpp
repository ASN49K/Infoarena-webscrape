#include <fstream>

using namespace std;
int cmmdc(int a, int b)
{
 if(b) return cmmdc(b,a%b);
  else return a;
}

int main()
{
    int a[1000][2],t;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=0;i<t;i++)f>>a[i][0]>>a[i][1];
    for(int i=0;i<t;i++)
    {
        g<<cmmdc(a[i][0],a[i][1]);
        g<<endl;
    }
  f.close();
  g.close();

}
