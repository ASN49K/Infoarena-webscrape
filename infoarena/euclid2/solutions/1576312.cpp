#include <fstream>

using namespace std;

int main()
{
    int n , i, p, s;
    ifstream fin ("suma.in");
    ofstream fout ("suma.out");

    fin >> n >> p;
    s = 0;
            if ((n-1)%3==0)
            {
                s = (n-1)/3;
                s = (1LL * s * n)%p;
                s = (1LL * s *(n+1))%p;
            }
            if ( n % 3 == 0)
            {
                s = n/3;
                s = (1LL * s * (n-1))%p;
                s = (1LL * s * (n+1))%p;
            }
            if ((n+1) % 3 == 0)
            {
                s = (n+1)/3;
                s = (1LL * s * (n-1))%p;
                s = (1LL * s * n)%p;
            }

    fout << s <<"\n";

    fin.close();
    fout.close();
    return 0;
}
