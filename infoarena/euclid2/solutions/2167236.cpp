#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

        int a,b,n,t;
        f >> n;
        for (int c=0;c<n;c++)
            { f >> a;
              f >> b;
              while (b!=0)
                    {t = a % b;
                    a = b;
                    b=t; }
              g << a << endl;
            }


    f.close();g.close();
    return 0;
}
