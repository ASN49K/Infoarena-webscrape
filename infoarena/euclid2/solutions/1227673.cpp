#include <fstream>

using namespace std;

int main()
{
    int x,y,r1,i,n;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    i=n;
    while (i>0)
        {
        fin>>x>>y;
        while(y>0)
            {
            r1=x%y;
            x=y;
            y=r1;
            }
        fout<<x<<"\n";
        i--;
        }
    fin.close();
    fout.close();
    return 0;
}
