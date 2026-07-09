#include <iostream>
#include <fstream>

using namespace std;

int n, x, y;

int euclid(int a, int b)
{
	int x = a, y = b;
    int c;
    while (b) 
    {
        c = a % b;
        a = b;
        b = c;
    }
    if(x < y)
      return x / a;
    else
      return y / a;
}
int main()
{
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");

    in >> n;
    for(int i = 0; i < n; i++)
    {
        in >> x >> y;
        out << euclid(x, y);
    }
    return 0;
}
