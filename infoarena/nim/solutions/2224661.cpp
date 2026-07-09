#include <bits/stdc++.h>

using namespace std;


ifstream fin ("nim.in");
ofstream fout("nim.out");

int no_of_Tests, no_of_Packs, no_of_Stones, current_Sum;

int main()
{
    fin>>no_of_Tests;

    while ( no_of_Tests-- )
    {
        fin>>no_of_Packs;
        current_Sum = 0;

        for ( int i = 1; i <= no_of_Packs; ++i )
        {
            fin>>no_of_Stones;
            current_Sum ^= no_of_Stones;
        }

        if ( current_Sum == 0 )
            fout<<"NU"<<'\n';
        else
            fout<<"DA"<<'\n';
    }
}
