#include <iostream>
#include <fstream>
using namespace std;

void seteaza(int x, int y)
{
    int c=0;
    if(x > y)
    {
        c = x;
        y = c;
        x = y;
    }
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n, a, b;
    fin >> n;
    for(int i=1; i<=n; i++)
    {
        fin >> a >> b;
        seteaza(a, b);
        while(a!=b)
            a-=b;
        cout << a;
    }
    return 0;
}


