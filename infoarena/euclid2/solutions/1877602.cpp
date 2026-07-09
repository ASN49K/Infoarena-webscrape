// Algoritmul lui Euclid

// Nenea Euclid a zis asa: cel mai mare divizor comun dintre 2 numere este primul numar daca al doilea este 0
// sau este tot una(egal) cu cel mai mare divizor comun dintre al doilea si restul impartirii primului la al doilea

#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
/*    if (b == 0)
    {
        return a;
    }
    else
    {
        return cmmdc(b, a % b);
    }*/
    
    int c;
    while (b != 0)
    {
        c = b;
        b = a % b;
        a = c;
    }
    
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    
    int t;
    fin >> t;
    
    int a, b;
    for (int i = 0; i < t; i++)
    {
        fin >> a >> b;
        
        fout << cmmdc(a, b) << endl;
    }
    
    fin.close();
    fout.close();
    
    return 0;
}