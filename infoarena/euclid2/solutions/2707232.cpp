#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int Euclid2(int x,int y)
{   if(!y)
    return x;
    else
        return Euclid2(y,x%y);
}

int main()
{   int n,a,b;
    fin >> n;
    for(int i=1; i<=n; ++i)
    {
        fin >> a >> b;
        fout << Euclid2(a,b) << "\n";
    }

    return 0;
}


