#include <fstream.h>

int n, a, b;

int euclid(int a, int b)
{   if (b==0) return a;
    else return euclid(b, a%b);
}

int main(void)
{   ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    f >> n;
    for (;n;--n)
    {   f >> a >> b;
	g << euclid(a, b) << "\n";
    }
    return 0;
}