#include <stdio.h>
#include <unistd.h>

#define CHUNK (1 << 21)

static char ibuf[CHUNK], obuf[CHUNK];
static size_t ibpos, obpos;

static inline unsigned read_int(char end)
{
    unsigned x = 0;

    while (ibuf[ibpos] != end) {
        x = x * 10 + (ibuf[ibpos] - '0');
        ibpos++;
    }

    ibpos++;
    return x;
}

static inline void write_int(unsigned n)
{
    size_t x, pf = 0;

    if (n == 0) {
        obuf[obpos++] = '0';
        obuf[obpos++] = '\n';
    }

    for (x = 1000000000; x > 0; x /= 10) {
        if (n / x > 0) {
            pf = 1;
        }

        if (pf) {
            obuf[obpos++] = '0' + n / x;
        }

        n %= x;
    }

    obuf[obpos++] = '\n';
}

int main(void)
{
    unsigned n, a, b, r;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    read(STDIN_FILENO, ibuf, CHUNK);

    n = read_int('\n');
    while (n--) {
        a = read_int(' ');
        b = read_int('\n');

        while (a % b) {
            r = a % b;
            a = b;
            b = r;
        }

        write_int(b);
    }

    write(STDOUT_FILENO, obuf, obpos);

    return 0;
}

