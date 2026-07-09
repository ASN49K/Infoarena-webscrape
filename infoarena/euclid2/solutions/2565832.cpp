#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("eucid2.out");

int n, a, b, r;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        if(a > b)
            swap(a,b);
        while(a != 0)
        {
            r = b % a;
            b = a;
            a = r;
        }
        cout  << b;
    }
    return 0;
}
