#include <iostream>
#include <fstream>
#include <map>

using namespace std;

ifstream f ("nim.in");
ofstream g ("nim.out");

int xors , n , i , k , a;

int main()
{
    f >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        f >>k;
        xors = 0;
        for (int j = 1 ; j <= k ; j++)
            f >> a , xors = xors ^ a;
        if (xors)
            g <<"DA" << '\n';
        else
            g << "NU" <<'\n';
    }

    return 0;
}
