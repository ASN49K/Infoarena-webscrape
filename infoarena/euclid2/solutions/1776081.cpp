#include <fstream>

using namespace std;

ifstream fin ("cmmdc.in");
ofstream fout ("cmmdc.out");

unsigned long int a, b, r, A, B;

int main()
{
    fin >> a >> b;
    if (a==0 || b==0)
        fout << 0;
    else{
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

     if (a==1)
        fout << 0;
     else
        fout << a;
    }
    return 0;
}
