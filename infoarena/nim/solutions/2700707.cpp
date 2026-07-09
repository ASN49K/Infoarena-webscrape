#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);

    int t,n,i,x,xor_sum;
    fin >> t;
    while(t--)
    {
        fin >> n;
        xor_sum = 0;
        for(i = 1; i <= n; i++)
        {
            fin >> x;
            xor_sum = xor_sum ^ x;
        }
        if(!xor_sum)
            fout << "NU\n";
        else
            fout << "DA\n";
    }
    return 0;
}
