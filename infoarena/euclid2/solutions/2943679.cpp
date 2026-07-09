#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    int r;

    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int euclidRecursiv(int a, int b)
{
    if(b == 0)
    {
        return a;
    }

    euclidRecursiv(b, a % b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t, i, a, b;

    fin >> t;

    for(i = 0; i < t; i++)
    {
        fin >> a >> b;

        fout << euclid(a, b) << '\n';
        //fout << euclidRecursiv(a, b) << '\n';
    }
    return 0;
}
