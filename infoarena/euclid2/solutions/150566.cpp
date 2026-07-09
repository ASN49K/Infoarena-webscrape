#include<fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main ()
{
    long long unsigned a,b,c,min;
    fin>>a>>b;
    if(a>b)
    min=b;
    else min=a;
    for(c=min;c>=0;c--)
    {
    if(a%c==0 && b%c==0)
    break;
}
    fout<<c;
    return 0;
}
