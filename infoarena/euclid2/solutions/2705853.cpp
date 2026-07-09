#include <bits/stdc++.h>

using namespace std;

ifstream fisierulDeIntrare("euclid2.in");
ofstream fisierulDeIesire("euclid2.out");

int numarulDeTeste, primulNumar, alDoileaNumar;
int celMaiMareDivizorComun(int,int);

int main()
{
    fisierulDeIntrare >> numarulDeTeste;

    for(; numarulDeTeste ; numarulDeTeste--)
    {
        fisierulDeIntrare >> primulNumar >> alDoileaNumar;
        fisierulDeIesire << celMaiMareDivizorComun(primulNumar, alDoileaNumar) << '\n';
    }

    return 0;
}
int celMaiMareDivizorComun(int numarulMaiMare, int numarulMaiMic)
{
    if(numarulMaiMic == 0)
        return numarulMaiMare;
    return celMaiMareDivizorComun(numarulMaiMic ,numarulMaiMare % numarulMaiMic);
}
