#include<fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long n,i,a,b,m;
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>a>>b;
        do
        {
            m=a%b;
            a=b;
            b=m;
        }while(m!=0);
        g<<a<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
