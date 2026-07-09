#include <iostream>
#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int T, v[100000],k;

int Euclid(int a, int b)
{
    int r;

    while(b)
    {
        r = a % b;
        a = b;
        b = r;

    }
    return a;
}

int main()
{
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;
        v[k++] = Euclid(a, b);
    }
    for(int i = 0; i < k; i++)
        cout << v[i] << '\n';
    return 0;
}
