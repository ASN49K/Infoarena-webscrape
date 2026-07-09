#include <fstream>
using namespace std;
ifstream fin("adunare.in");
ofstream fout("adunare.out");
int main()
{   int A,B;
    fin>>A>>B;
    fout <<A+B<< endl;
    return 0;
}
