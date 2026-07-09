#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int n;
    int a;
    int b;
    int r;

    f >> n;

    for(int i = 1; i <= n; i++)
    {
        f >> a >> b;

        do{
            r = a % b;
            a = b;
            b = r;
        }
        while (r != 0);

        g << a << endl;
    }

    f.close();
    g.close();

    return 0;
}
