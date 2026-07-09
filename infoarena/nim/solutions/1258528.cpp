#include <fstream>

using namespace std ;

int N, T, A, sum ;

ifstream fin("nim.in") ;
ofstream fout("nim.out") ;

int main()
{

    fin >> T ;

    while(T --)
    {

        fin >> N ;
        sum  = 0 ;
        for(int i = 1 ; i <= N ; ++ i)
        {
            int a ;
            fin >> a ;
            sum = sum ^ a ;
        }
        if(sum)
            fout << "DA" << '\n' ;
        else fout << "NU" << '\n' ;
    }

    fin.close() ;
    fout.close() ;
    return  0 ;
}
