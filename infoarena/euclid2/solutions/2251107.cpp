#include<f>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int n,a,b,r;
    fin>>n;
    while(n!=0)
    {
        fin>>a>>b;
        n--;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";

    }
fin.close();
fout.close();
    return 0;
}
