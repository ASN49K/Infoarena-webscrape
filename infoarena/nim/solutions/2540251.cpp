#include <iostream>
#include <fstream>
using namespace std;

int v[10000], t, x, i, n;

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

    while(t > 0)
    {
        f >> n;
        while(n > 0)
        {
            f >> x;
            i = 0;
            while(x > 0)
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


        for( int l = 1; l <= 9999; l++)
            v[l] = 0;

        t--;
    }



    return 0;
}

