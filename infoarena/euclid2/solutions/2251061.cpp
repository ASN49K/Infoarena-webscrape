#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int CMMDC(int a,int b)
{
    if(b==0)return a;
    return CMMDC(b,a%b);
}


int main()
{

    int n,a,b;

    fin >> n;

    for(int i=1;i<=n;++i)
    {
    fin >> a >> b;
    fout << CMMDC(a,b) << endl;
    }




    return 0;
}
