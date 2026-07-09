#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a, b, t;

    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin >> t;
    while( t > 0)
    {

        fin >> a;
        fin >> b;

        while(a != b)
        {
            if(a > b)
            {
                a -= b;

            }
            else
            {
                b -= a;
            }
        }
        fout<< a << endl;
        t--;
    }
    return 0;
}
