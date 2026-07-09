#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int n,a,b,r,aux;
    fin>>n;
    while (n>0)
        {
        fin>>a>>b;
        if (b>a)
            {
            aux=a;
            a=b;
            b=aux;
            }
        r=a%b;
        while (r!=0)
            {
            a=b;
            b=r;
            r=a%b;
            }
        fout<<b<<"\n";
        n--;
        }
    fin.close();
    fout.close();
    return 0;
}
