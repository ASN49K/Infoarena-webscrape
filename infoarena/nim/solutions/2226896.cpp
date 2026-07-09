#include <cstdio>

using namespace std;

FILE *f, *g;

int crChar = 4096;

int crPrint = 0;

const int buffSize = 4096;

char buff[4100];

char buffPrint[4100];

bool isDigit[300];

void getIsDigit()
{
    int i;
    for(i = '0'; i <= '9'; i ++)
        isDigit[i] = 1;
}

void refillBuff()
{
    crChar = 0;

    fread(buff, 1, buffSize, f);
}

char getCr()
{
    if(crChar == buffSize)
        refillBuff();

    return buff[crChar ++];
}

int getNr()
{
    int nr = 0;
    int sign = 1;

    char c = getCr();

    while(isDigit[c] == 0 && c != '-')
        c = getCr();

    while(c == '-')
    {
        sign *= -1;

        c = getCr();
    }

    while(isDigit[c] == 1)
    {
        nr = nr * 10 + c - '0';

        c = getCr();
    }

    return nr * sign;
}

void printCr(char c)
{
    if(crPrint == buffSize)
    {
        fwrite(buffPrint, 1, buffSize, g);

        crPrint = 0;
    }

    buffPrint[crPrint ++] = c;
}

char v[10];

int cif;

void addPrint(int a)
{
    if(a == 0)
        printCr('0');

    cif = 0;

    while(a > 0)
    {
        v[++ cif] = a % 10 + '0';

        a /= 10;
    }

    for(; cif >= 1; cif --)
        printCr(v[cif]);

    printCr('\n');
}

void readFile()
{
    f = fopen("nim.in", "r");
    g = fopen("nim.out", "w");

    getIsDigit();

    int t, n, theSum;
    t = getNr();

    for(; t > 0; t --)
    {
        n = getNr();

        theSum = 0;

        for(; n > 0; n --)
        {
            theSum ^= getNr();
        }

        if(theSum != 0)
            printCr('D'), printCr('A');

        else
            printCr('N'), printCr('U');

        printCr('\n');
    }

    fwrite(buffPrint, 1, crPrint, g);

    fclose(f);
    fclose(g);
}

int main()
{
    readFile();

    return 0;
}
