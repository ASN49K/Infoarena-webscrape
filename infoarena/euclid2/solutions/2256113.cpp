#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int x, int y)
{
    if(y==0)
        return x;
    return(y, y%x);

}

int main()
{
    int x, nr1, nr2;
    fin >> x;
    for(int i = 1; i <= x; i++)
    {
        fin >> nr1 >> nr2;
        fout << euclid(nr1, nr2) << "\n";
    }
    return 0;
}
