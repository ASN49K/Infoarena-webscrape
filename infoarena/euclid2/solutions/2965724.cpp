#include <fstream>

using namespace std ;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t,a,b;

int main()
{
    fin >> t;
    for(int i = 0 ; i < t  ;i++)
        {
            fin >> a >> b;
            int div;
            while(b != 0)
                {
                    div = b ;
                    b = a % b ;
                    a = div ;
                }
            fout << a << '\n';
        }

    fin.close();
    fout.close();
    return 0;
}
