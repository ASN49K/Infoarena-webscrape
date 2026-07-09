#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

        int a,b,n;
        f >> n;
        for (int c=0;c<n;c++)
            { f >> a;
              f >> b;
              while (a!=b)
                     if (a<b) b=b-a;
                     else a=a-b;
              g << a << endl;
            }


    f.close();g.close();
    return 0;
}
