#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("nim.in");
ofstream g ("nim.out");

int main()
{
    int N,M;
    f>>N;
    for(int i=1; i<=N; i++)
    {
        int s=0;
        f>>M;
        for(int j = 1; j<= M; j++)
        {
            int element;
            f>>element;
            s ^= element;
        }
        if(s)
            g<<"DA"<<"\n";
        else g<<"NU"<<"\n";
    }


    return 0;
}
