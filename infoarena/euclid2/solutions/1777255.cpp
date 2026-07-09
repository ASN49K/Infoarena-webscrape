#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out("euclid2.out");

int t, nr1, nr2;

int main()
{
    in >> t;
    for(; t > 0; --t)
    {
        in >> nr1 >> nr2;

        while(true)
        {
            if(nr1 == nr2)
            {
                out << nr1 << "\n";
                break;
            }
            if(nr1 > nr2)
            {
                nr1-= nr2;
            }
            else if(nr1 < nr2)
            {
                nr2-= nr1;
            }
        }
    }
}
