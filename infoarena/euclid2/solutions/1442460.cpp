#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char in_file[30] = "euclid2.in";
    char out_file[30] = "euclid2.out";

    ifstream in(in_file, ios::in);
    ofstream out(out_file, ios::out);

    int n_pairs = 0;
    int a;
    int b;
    int N1;
    int N2;

    in >> n_pairs;
    int modulo = 0;

    for(int i = 0; i < n_pairs; i++)
    {
        in >> a >> b;

        if(a <= b)
        {
            N1 = a;
            N2 = b;
        }
        else
        {
            N1 = b;
            N2 = a;
        }

        modulo = N2 % N1;
        while(modulo != 0)
        {
            modulo = N2 % N1;   //determine the modulo
            N2 = N1;            //swap the numbers and initialize the minimum no with the modulo
            N1 = modulo;
            modulo = N2 % N1;
        }

        out << N1 << endl;
    }

}
