#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main()
{
    int i,n,x,y,r,a,b;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<"\n";
    }


    fout.close();
    return 0;
}
