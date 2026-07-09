#include <fstream>

using namespace std;

int main()
{
    int n, t, sumaxor, x;
    ifstream f("nim.in");
    ofstream g("nim.out");
    f>>t;
    while(t)
    {
        t--;
        f>>n;
        sumaxor = 0;
        while(n)
        {
            n--;
            f>>x;
            sumaxor = sumaxor ^ x;
        }
        if (sumaxor > 0)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    f.close();
    g.close();

    return 0;
}
