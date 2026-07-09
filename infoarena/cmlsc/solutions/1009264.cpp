#include <iostream>
#include <fstream>

int main ()
{
    int n, a, b;  
    std::ifstream f("euclid2.in");   
    std::ofstream fout("euclid2.out");
    f>>n;

    for(int i=0;i<n;i++)
    {   
        f>>a>>b;  
        while(!a || !b)
        {
            
        }
        fout<<euclid(a,b)<<std::endl;
    }
    return 0;
}
