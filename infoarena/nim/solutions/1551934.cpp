#include<fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int T,N;

int main()
{
    fin>>T;

    while(T--)
    {
        fin>>N;

        int xsum=0;

        for(int i=1;i<=N;++i)
        {
            int a;  fin>>a;
            xsum = xsum ^ a;
        }

        if(xsum)    fout<<"DA\n";
        else    fout<<"NU\n";
    }

    fin.close();
    fout.close();
    return 0;
}
