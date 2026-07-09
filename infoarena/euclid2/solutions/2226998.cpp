#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

void euclid(int a, int b, int *r)
{
     if(b==0)
       *r=a;
     else
        euclid(b, a%b, r);
}

int main()
{
    int a, b, n, *r, i;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        /*while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;

        }
        fout<<a<<"\n";*/
        euclid(a, b, r);
        fout<<*r<<"\n";

    }
    return 0;
}
