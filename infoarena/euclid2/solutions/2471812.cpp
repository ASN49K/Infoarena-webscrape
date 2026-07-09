#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid2.out");
int t, a, b, v[100001];
int main()
{
    int c;
    fin>>t;
    int i=0;
    while(t!=i)
    {
        fin>>a>>b;
        while (b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        v[i]=a;
        i++;
        fout<<a<<" "<<b<<endl;

    }
    for(int j=0;j<i;j++)
        fout<<v[j]<< " ";
    return 0;
}
