#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int n;
    fin >> n;
    for(int i=1;i<=n;i++)
    {
        int a, b;
        fin >> a >> b;
        fout << euclid(a,b)<< '\n';
    }
    return 0;
}
