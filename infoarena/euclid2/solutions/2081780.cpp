#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid3(int a, int b)
{
    if(b==0)
        return a;
    else
        return euclid3(b,a%b);
}

int main()
{
    int n,a,b;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        if(a==0 || b==0)
            fout<<0<<endl;
        else
            fout<<euclid3(a,b)<<endl;
    }

    return 0;
}
