#include <fstream>
using namespace std;

const char infile[] = "nim.in";
const char outfile[] = "nim.out";

int main(int argc, char* argv [])
{
    fstream fin(infile, ios::in);
    fstream fout(outfile, ios::out);
    
    int nrJocuri;
    fin >> nrJocuri;
    
    for(int i = 0; i < nrJocuri; i++)
    {
        int nrGramezi;
        int sumaXor;
        sumaXor ^= sumaXor;
        fin >> nrGramezi;
        for(int j = 0; j < nrGramezi; j++)
        {
            int gramadaCurenta;
            fin >> gramadaCurenta;
            sumaXor ^= gramadaCurenta;
        }
        
        if(sumaXor == 0)
        {
            fout << "NU\n";
        }
        else
        {
            fout << "DA\n";
        }
    }

    fin.close();
    fout.close();
}
