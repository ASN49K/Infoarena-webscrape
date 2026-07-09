#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n,a,b,c;
    fin>>n;
    while(n)
    {
        fin>>a>>b;
        if(a>b)
        {
            while(b)
            {
                c=a%b;
                a=b;
                b=c;
            }
            fout<<a<<"\n";
        }
        else
        {
            while(a)
            {
                c=b%a;
                b=a;
                a=c;
            }
            fout<<b<<"\n";
        }
        n--;
    }
    return 0;
}
