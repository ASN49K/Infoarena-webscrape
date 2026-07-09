//#include <iostream>

#include <fstream>

//#define fin cin
//#define fout cout

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

//ifstream fin("text.in");
//ofstream fout("text.out");

int main()
{
    unsigned short A[1025], M; // A vector with M elements
    unsigned short B[1025], N; // B vector with N elements

    fin >> M >> N;
    for (int i = 0; i < M; ++i)
        fin >> A[i];

    for (int i = 0; i < N; ++i)
        fin >> B[i];

    unsigned short destination_vector[1025], P = 0;

    for (int i = 0; i < M; ++i)
    {
        unsigned short current_vector[1025], Q = 0;
        unsigned int piv = 0; // pivotul pentru j

        for (int i2 = i; i2 < M && piv < N; ++i2)
            for (int j = piv; j < N; ++j)
                if (A[i2] == B[j])
                {
                    current_vector[++Q] = B[j];
                    piv = j + 1;
                    break;
                }

        /*
        cout << '\n' << Q << '\n';
        for (int j = 1; j <= Q; ++j)
            cout << current_vector[j] << ' ';

        cout << "\n";
        */

        if (Q > P)
        {
            P = Q;
            for (int j = 1; j <= P; ++j)
                destination_vector[j] = current_vector[j];
        }
    }

    fout << P << '\n';
    for (int i = 1; i <= P; ++i)
        fout << destination_vector[i] << ' ';

    return 0;
}
