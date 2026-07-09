#include <fstream>

using namespace std;

int main()
{       int a,b,r,n,i;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

        fin >> n;
    for(i = 1;i<=n;i++)
    {
        fin >> a >> b;
            while(b)
            {
                r = a%b;

                a = b;
                b = r;
            }
        fout << a <<"\n";
    }

   fin.close();
   fout.close();
    return 0;
}
