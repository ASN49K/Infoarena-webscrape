# include <iostream>
# include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;
long int euclid (long int a, long int b)
{
    if (!b)
    return a;
    else
    return euclid (b,a%b);
}

int main ()
{
    long int x1,x2;
    f >> n;
    for (int i=1; i<=n; i++)
    {
        f >> x1 >> x2;
        g << euclid(x1,x2)<< '\n';
    }

    f.close();
    g.close();

}
