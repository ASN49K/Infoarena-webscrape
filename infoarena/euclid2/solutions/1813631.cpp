#include <fstream>

using namespace std;
int T;

int Cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{ int a, b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> T;

    for(int i=1; i <= T; i++)
    {
        fin >> a >> b;
        fout << Cmmdc(a,b)<<"\n";
    }


    return 0;
}
