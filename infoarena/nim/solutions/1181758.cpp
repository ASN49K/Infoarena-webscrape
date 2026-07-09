/*
    Keep It Simple!
*/

#include<fstream>
using namespace std;

int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");

    int T;
    f >> T;

    while(T--)
    {
        int N,x;
        f >> N;

        int s = 0;
        for(int i=1;i<=N;i++)
        {
            f >> x;
            s ^= x;
        }

        if(s > 0)
            g << "DA\n";
        else
            g << "NU\n";
    }
}
