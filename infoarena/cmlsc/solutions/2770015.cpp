#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
    std::ifstream fin("cmlsc.in");
    int16_t sizeA, sizeB;  fin >> sizeA >> sizeB;
    int16_t arrA[sizeA], arrB[sizeB];
    for(int16_t iii = 0; iii < sizeA;  ++iii)
        fin >> arrA[iii];
    for(int16_t iii = 0; iii < sizeB;  ++iii)
        fin >> arrB[iii];
    uint16_t tabelAparitie[sizeA+1][sizeB+1];
    for(int16_t iii = 0; iii <= sizeA; ++iii)   tabelAparitie[iii][0] = 0;
    for(int16_t iii = 0; iii <= sizeB; ++iii)   tabelAparitie[0][iii] = 0;
    for(int16_t iii = 1; iii <= sizeA; ++iii)
    {
        for(int16_t jjj = 1; jjj <= sizeB; ++jjj)
        {
            if(arrA[iii-1] == arrB[jjj-1])
                tabelAparitie[iii][jjj] = tabelAparitie[iii-1][jjj-1]+1;
            else
                tabelAparitie[iii][jjj] = (tabelAparitie[iii-1][jjj] > tabelAparitie[iii][jjj-1]) ? tabelAparitie[iii-1][jjj] : tabelAparitie[iii][jjj-1];
        }
    }
    
    int16_t index{}, answer[1024]{};
    for(int16_t iii = sizeA-1, jjj = sizeB-1; iii > 0;)
    {
        if(arrA[iii] == arrB[jjj])
        {
            answer[++index] = arrA[iii]; 
            --iii; --jjj;
        }
        else if(tabelAparitie[iii][jjj+1] < tabelAparitie[iii+1][jjj])
            --jjj;
        else
            --iii;
    }
    std::ofstream fout("cmlsc.out");
    fout << index << '\n';
    for(int16_t iii = index; iii > 0; --iii)
        fout << answer[iii] << ' ';
        
    fout.close();
    return 0;
}
