#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n , x , y;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>y;
        while(x != y)
        {
            if(x < y) y = y - x;
            else x = x - y;
        }
        fout<<x<<endl;
    }
    return 0;
}
