#include <iostream>
#include <fstream>

using namespace std;

long n;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    fin>>n;
    for(int i=0;i<n;i++)
    {
        long a,b;
        fin>>a>>b;
        while(b)
        {
            long c=a%b;
            a=b;
            b=c;
        }
        fout<<a<<"\n";
    }
    return 0;
}
