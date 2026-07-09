#include <iostream>
#include <fstream>
using namespace std;

int main()
{   int a, b, i, j, div, nr, maxim;
    ifstream f;
    ofstream g:

    f.open("euclid.in");
    g.open("euclid.out");

    f>>nr;

    for(i=0;i<nr;i++)
    {
        f>>a;
        f>>b;

        if(a>b) {maxim=a;} else {maxim=b;}

        j=1;
        while(j!=maxim)
        {
            if((a%j==0) && (b%j==0))
            {
                div=j;
            }
            j++;

        }
        g<<div<<"\n";
    }


    f.close();
    g.close();



    return 0;
}
