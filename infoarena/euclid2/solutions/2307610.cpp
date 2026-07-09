#include <fstream>

using namespace std;

int gcf(int a, int b)
{
    while (a != b)
    {
        ((a > b)? a:b) = ((a > b)? a:b) - ((a < b)? a:b);
    }
    return a;
}


int main()
{
    ofstream g("euclid2.out");
    ifstream f("euclid2.in");
    int a, b, T;

    f >> T;
    for (int i = 1; i <= T; i++)
    {
        f >> a >> b;
        g << gcf(a, b) << endl;
    }

    f.close();
    g.close();

    return 0;
}
