#include <iostream>
#include <fstream>

uint64_t euclid(uint64_t num1, uint64_t num2)
{
    while(num2 != 0)
    {
        uint64_t temp{num2};
        num2 = num1 % num2;
        num1 = temp;
    }
    
    return num1;
}

int main()
{
    std::ifstream fin("euclid2.in");
    uint32_t T; fin >> T;
    std::ofstream fout("euclid2.out");
    for(int iii = 0; iii < T; ++iii)
    {
        uint64_t a, b; fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }

    return 0;
}
