#include<fstream>
using namespace std;
int main()
{   ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b,i;
    f>>n;
     for(i=1;i<=n;i++)
     {
         f>>a>>b;
         while(b)
         {
             int r=a%b;
             a=b;
             b=r;
         }
       g<<a<<"\n";
     }
    f.close();
    g.close();
return 0;
}
