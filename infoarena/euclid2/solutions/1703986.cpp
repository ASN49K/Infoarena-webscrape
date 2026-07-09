#include <fstream>
#include <cmath>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main()
{
    int a, b, n, j;

    fin>>n;
    for(int g=1;g<=n;g++)
    {
        fin>>a>>b;
        if(a<b)
            swap(a,b);
        while(b!=0)
        {
            j=a%b;
            a=b;
            b=j;
        }
        fout<<a<<'\n';
    }

    return 0;
}
