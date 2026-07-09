#include <iostream>
#include <fstream>

std::ifstream fin("euclid.in");
std::ofstream fout("euclid.out");

int cmmdc(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return cmmdc(b, a%b);
    }
}

void rezolva()
{
    int n, a, b;
    fin>>n;
    for(int i = 0; i < n; i++)
    {
        fin>>a>>b;
        if(a>b)
        {
            fout<<cmmdc(a, b)<<'\n';;
        }
        else
        {
            fout<<cmmdc(b, a)<<'\n';;
        }
    }
}

int main()
{
    rezolva();
    return 0;
}
