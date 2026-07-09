#include <fstream.h>

int Cmmdc ( int a, int b)

int main()
{
    ifstream fin ("euclid2.in");
    
    int T, a, b, i;
    
    fin >> T;
    
    for ( i = 0; i < T; i++ )
    {
        fin >> a[i];
        fin >> b[i];
    
    fin.close();
    
    ofstream fout ("euclid2.out");
    
    for ( i = 0; i < T; i++ )
        fout << Cmmdc ( a, b ) << ' ';
    
    fout.close();
    
    return 0;
}

int Cmmdc ( int a, int b )
{
    if ( b == 0 ) return a;
    int rest;
    do
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    while ( rest != 0 )
    
    return a;
}
    
    
    
    
    
    
    
       
