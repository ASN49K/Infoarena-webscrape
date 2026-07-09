#include <fstream>

using namespace std;

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");

    int t,n,i,j;
    int x,p;
    fin>>t;
    for(i=0;i<t;i++)
    {
        fin>>n;
        p=0;
        for(j=0;j<n;j++)
        {
            fin>>x;
            p^=x;
        }
        if(p>0)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    fin.close();
    fout.close();
    return 0;
}
