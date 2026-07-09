#include <iostream>
#include <fstream>

void swapNumbers(int& a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}


int cmmdc(int a, int b)
{
    /*set a as largest element*/
    if(a < b)
    {
        swapNumbers(a,b);
    }

    while(a != 0)
    {
        if(a % b == 0)
        {
            return b;
        }
        else
        {
            int r = a % b;
            a = b;
            b = r;
        }
    }
}


int main()
{
    int n;
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");
    
    fin >> n;
 
    for(int i = 1 ; i <= n; i++)
    {
        int a, b;
        fin >> a >> b;
        fout << cmmdc(a,b) << "\n";
    }

    fout.flush();
    fin.close();
    fout.close();
    
    return 0;
}
