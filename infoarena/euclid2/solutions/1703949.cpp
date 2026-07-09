#include <fstream>

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
        j=1;
        for(int i=2;i<=a;i++)
        {
            while(a%i==0 and b%i==0)
            {
                a=a/i;
                b=b/i;
                j=j*i;
            }
            if(a==1 or b==1)
                break;
        }
        fout<<j<<'\n';
    }

    return 0;
}
