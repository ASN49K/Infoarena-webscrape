#include <fstream>
#include <iostream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclide.out");
int T[100001];
int l;
int main ()
{
    int x;
    fin >> x;
    while (x)
    {
        int a, b;
        fin >> a >> b;
        while (b)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        T[++l] = a;
        x--;
    }
    for (int i = 1; i <= l; i++)
        cout << T[i] << "\n";
}
