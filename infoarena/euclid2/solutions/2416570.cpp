#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)

{

    if(!b)
        return a;
    else
        return euclid(b, a%b);

}

int main()
{

    int T, a, b;
    fin >> T;
        for(; T;--T)
        {
          fin >>a; fin>>b;
          fout << euclid(a, b)<<endl;
        }


    return 0;
}
