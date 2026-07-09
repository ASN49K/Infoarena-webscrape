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

        while(b != 0)
        {
            int temp=a;
            a = b;
            b = temp % b;
        }
        fout<< a << endl;
        t--;
    }
    return 0;
}
