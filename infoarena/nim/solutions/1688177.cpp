#include<fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int T,N,x,sum;
int main()
{
    fin>>T;
    while(T--)
    {
        fin>>N;
        sum=0;
        for(int i=1;i<=N;i++)
        {
            fin>>x;
            sum^=x;
        }
        if(sum)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    return 0;
}
