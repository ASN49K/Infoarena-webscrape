#include <fstream>

using namespace std ;

int T, A, B ;
ifstream fin("euclid2.in") ;
ofstream fout("euclid2.out");

void GCD(int a, int b)
{
    if(b == 0 )
        {fout << a << '\n' ;
        return  ;
        }
    return GCD(b, a % b) ;
}

int main()
{
    fin >> T ;
    while(T --)
    {
        fin >> A >> B  ;
        GCD(A, B);
    }
    fin.close() ;
    fout.close() ;
    return  0 ;

}
