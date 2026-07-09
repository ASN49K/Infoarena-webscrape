#include<fstream>

using namespace std;
int n,i,a,b,r;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
         do
        {
        r=a%b;
        a=b;
        b=r;
        }
        while(r!=0);
        g<<a<<"\n";
    }
}
