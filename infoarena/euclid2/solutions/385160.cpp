#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t,a,b,r;
    fin>>t;
    for (int i=1;i<=t;i++)
        {
            fin>>a>>b;
            while (a%b!=0)
                {
                    r=a%b;
                    a=b;
                    b=r;
                }
            fout<<b<<endl;
        }
    fin.close();
    fout.close();
    return 0;
}
