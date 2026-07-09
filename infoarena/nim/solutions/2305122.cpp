#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("nim.in");
    ofstream out("nim.out");
    int t;
    in >> t;
    while(t--)
    {
        int n;
        in >> n;
        int s = 0, x;
        while(n--)
        {
            in >> x;
            s ^= x;
        }
        if(s)
            out << "DA\n";
        else
            out << "NU\n";
    }
    in.close();
    out.close();
    return 0;
}
