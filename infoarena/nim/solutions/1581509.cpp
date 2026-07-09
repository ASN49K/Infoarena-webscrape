#include <iostream>
#include <fstream>

using namespace std;
    ifstream in("nim.in");
    ofstream out("nim.out");

int main()
{   int n, t, x, i, xorsuma;
    in >> t;

    while(t--)
    {   in >> n;

        xorsuma = 0;
        for(i = 1; i <= n; i++)
        {   in >> x;
            xorsuma = xorsuma ^ x;
        }
    if(xorsuma) out << "DA" << "\n";
        else out << "NU" << "\n";

    }
    return 0;
}
