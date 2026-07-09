#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(!b)
    {
        return a;
    }
    else
    {
        return cmmdc(b,a%b);
    }
}
int main()
{
    int t;
    fin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    fin.close();
    fout.close();

    return 0;
}
