#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    short int N,i,k,j;
    ifstream f("fractii.in");
    ofstream g("fractii.out");
    f>>N;
    k=N;
    for (i=2;i<=N;i++)
    {
        for (j=1;j<=N;j++)
        {
            if (i%2==0 and (j%3==0 or j==1)and i!=j)
            {
                k++;
            }
            else if (i%3==0 and (j%2==0 or j==1)and i!=j)
            {
                k++;
            }
        }
    }
    g<<k;
    f.close(),g.close();
    return 0;
}
