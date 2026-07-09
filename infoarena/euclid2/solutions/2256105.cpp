#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    if(b)
        return a;
    return(b, b%a);

}

int main()
{
    int x;
    int nr1, nr2;
    fin >> x;
    for(int i = 1; i <= x; i++)
    {
        fin >> nr1 >> nr2;
        fout << euclid(nr1, nr2) << "\n";
    }
    return 0;
}
