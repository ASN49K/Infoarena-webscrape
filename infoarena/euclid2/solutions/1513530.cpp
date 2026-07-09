#include <fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

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
