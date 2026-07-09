#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

int main()
{
    int a,b,r;
    fin>>a>>b;
    while(r!=0)
    {   r=a%b;
        a=b;
        b=r;
    }
    fout<<a;

    return 0;
}
