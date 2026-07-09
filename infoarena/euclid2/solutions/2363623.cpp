#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, a, b, d, rest, i;
int main()
{
    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin>>a>>b;
        while(a!= b)
        {
            if(a>b)
                a=a-b;
            if(b>a)
                b=b-a;
        }
        fout<<a<<endl;
    }

    return 0;
}
