#include<fstream>
long int n,q,k;
using namespace std;
long int gcd(int a,int b)
{
    if (a==0){return b;}
    {return gcd(b%a,a);}
}
int main()
{
    ifstream fi("euclid2.in");
    ofstream fo("euclid2.out");
    fi>>n;
    for (int i=0;i<n;++i)
    {
        fi>>q>>k;
          fo<<gcd(q,k)<<'\n';
    }

    fi.close();fo.close();
    return 0;
}
