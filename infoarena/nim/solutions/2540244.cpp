#include <iostream>
#include <fstream>
using namespace std;

int v[1000], t, x, i, n;

int Verif(int l)
{
    int j;
    for(j = 1; j <= l; j++)
    {
            if(v[j] == 1)
                return 1;
    }
    return 0;
}


int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");

    f >> t;

    while(t)
    {
        f >> n;
        while(n)
        {
            f >> x;
            i = 0;
            while(x)
            {
                i++;
                if( x % 2 == 1 )
                {
                    if(v[i] == 0)
                        v[i] = 1;
                    else
                        v[i] = 0;
                }
                x = x/2;
            }



            n--;
        }
        if(Verif(i) == 1)
            g<<"DA\n";
        else
            g<<"NU\n";


        t--;
    }



    return 0;
}

