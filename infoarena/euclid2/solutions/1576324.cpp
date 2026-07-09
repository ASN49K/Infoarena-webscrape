#include <fstream>

using namespace std;
int main()
{
    ifstream fin (" euclid2.in");
    ofstream fout (" euclid2.out");
    int a, r , b;
    fin >> a>> b;
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    fout << a <<  "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
