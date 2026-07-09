# include <fstream>
using namespace std;
ifstream fi("nim.in");
ofstream fo("nim.out");
int main(void)
{
    int t,n;
    for (fi>>t;t--;)
    {
        fi>>n;int S=0,x;
        for (int i=1;i<=n;++i) fi>>x,S^=x;
        if (S) fo<<"DA\n"; else fo<<"NU\n";
    }
}
