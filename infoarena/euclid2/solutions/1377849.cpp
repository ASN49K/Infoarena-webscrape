#include<fstream>
using namespace std;
ifstream fin("euclid2.in");ofstream fout("euclid2.out");
unsigned long a,b,r,n,i;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;r=a%b;
        while (b)
        {
            r=b;
            b=a%b;
            a=r;
        }
        //if(a==1)a=0;
        fout<<a<<'\n';
    }
    fin.close();fout.close();
}
