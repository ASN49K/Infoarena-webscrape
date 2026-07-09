#include <fstream>


using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int x;
    int nr1, nr2, rest;
    fin >> x;


    for(int i = 1 ; i <= x; i++)
    {
     fin >> nr1 >> nr2;
        while(nr2!=0)
        {
            rest = nr1 % nr2;
            nr1 = nr2;
            nr2 = rest;
        }

         fout << nr1 <<"\n";
    }


}
