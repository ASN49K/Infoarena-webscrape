#include <iostream>
#include <fstream>

/*   */

using namespace std;

int cmmdc(int a, int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    int a,b,n;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
