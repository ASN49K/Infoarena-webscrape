#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000

typedef struct sheep {
    int steps;
    int wool;
} Sheep;

// Compare sheep by distance and by steps.
int sheepCompare(const Sheep *sheep1, const Sheep *sheep2) {
    if (sheep1->wool > sheep2->wool) return -1;
    if (sheep1->wool < sheep2->wool) return 1;
    if (sheep1->steps > sheep2->steps) return 1;
    if (sheep1->steps < sheep2->steps) return -1;
    return 0;
}

int main() {
    int n, x, l, num; // Number of entries, max distance the wolf can trave, distance sheep go away, and number of entries that count.
    int d, a;
    int i, j;
    int maxSteps;
    Sheep sheepList[MAXN];

    FILE *fin, *fout;

    fin = fopen("lupu.in", "r");
    fout = fopen("lupu.out", "w");


    // Read variables from files
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &x);
    fscanf(fin, "%d", &l);
    maxSteps = x / l + 1;
    j = 0;
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d", &d);
        fscanf(fin, "%d", &a);
        if (d <= x && a > 0) {
            // Store in terms of the maximum number of sheep the wolf can get before going for this sheep
            sheepList[j].steps = (x - d) / l;
            // Trim the the last part because the maximum number of sheep the wolf can get
            // before going for it is not relevent when the MAX number of sheeps that exist
            // is smaller.
            if (sheepList[j].steps >= MAXN) {
                sheepList[j].steps = MAXN - 1;
            }
            sheepList[j].wool = a;
            j++;
        }
    }
    num = j;

    // Order decreasingly by wool then increasingly by steps
    qsort(sheepList, num, sizeof(Sheep), sheepCompare);

    // Debug
//    for (i = 0; i < num; i++) {
//        printf("%d %d\n", sheepList[i].steps, sheepList[i].wool);
//    }
    // End Debug


    int stepList[MAXN];
    int next[MAXN];
    int prevSearch;
    for (i = 0; i < MAXN; i++) {
        stepList[i] = 0;
        next[i] = i;
    }
    // Compute the steps
    int searchPos;
    for (i = 0; i < num; i++) {
        searchPos = sheepList[i].steps;
        searchPos = next[searchPos];
        prevSearch = searchPos;
        while (searchPos >= 0 && stepList[searchPos] != 0) {
            //if (next[searchPos] != -2) {
            //if (searchPos >= 0) searchPos--;
            searchPos = next[searchPos];
            next[prevSearch] = searchPos;
            //if (searchPos >= 0 && stepList[searchPos] != 0) searchPos--;
        }
        next[sheepList[i].steps] = searchPos - 1;
        if (searchPos < 0) continue;
        next[searchPos] = searchPos - 1;

        stepList[searchPos] = sheepList[i].wool;
    }

    long long woolSum = 0;
    for (i = 0; i < MAXN; i++) {
        woolSum += stepList[i];
    }

    fprintf(fout, "%lld\n", woolSum);
    printf("%lld\n", woolSum);
    // Debug
//    for (i = 0; i < 10; i++) {
//        printf("%d ", stepList[i]);
//    }
    // End Debug

    fclose(fin);
    fclose(fout);
    return 0;
}
