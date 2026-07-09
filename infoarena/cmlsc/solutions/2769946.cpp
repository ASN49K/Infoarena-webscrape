#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
    std::ifstream fin("cmlsc.in");
    uint16_t sizeA, sizeB;  fin >> sizeA >> sizeB;
    uint16_t arrA[sizeA], arrB[sizeB];
    for(uint16_t iii = 0; iii < sizeA;  ++iii)
        fin >> arrA[iii];
    for(uint16_t iii = 0; iii < sizeB;  ++iii)
        fin >> arrB[iii];
    std::sort(arrA, arrA+sizeA);
    std::sort(arrB, arrB+sizeB);
    
    uint16_t indexA{}, indexB{}, index{}, answer[1025];
    while(indexA < sizeA && indexB < sizeB)
    {
        if(arrA[indexA] == arrB[indexB])
        {
            answer[index] = arrA[indexA];
            ++index, ++indexA, ++indexB;
        }
        else if(arrA[indexA] < arrB[indexB])
                ++indexA;
        else    ++indexB;
    }
    std::ofstream fout("cmlsc.out");
    fout << index << '\n';
    for(uint16_t iii = 0; iii < index; ++iii)
        fout << answer[iii] << ' ';
        
    return 0;
}
