#include <fstream.h>

int Cmmdc();

int a, b, T;

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    
    fin >> T;
    
    int i;
    
    for ( i = 0; i < T; i++)
    {
        fin >> a >> b;
        fout << Cmmdc();
        fout << '\n';
    }
    
    fin.close();
    fout.close();
    
    return 0;
}

int Cmmdc()
{
    int r;
    while ( b )
    {
          r = a % b;
          a = b;
          b = r;
    }
    return a;
}
