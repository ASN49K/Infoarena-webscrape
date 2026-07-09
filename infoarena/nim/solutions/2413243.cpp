#include<fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int a,t,sum,n,i;
int main()
{
    fin>>t;
    while(t!=0)
    {
        fin>>n;
        sum=0;
        for(i=1;i<=n;i++)
        {
            fin>>a;
            sum=sum^a;
        }
        if(sum!=0)
            fout<<"DA\n";
        else
            fout<<"NU\n";
        t--;
    }
    fin.close();
    fout.close();
    return 0;
}

