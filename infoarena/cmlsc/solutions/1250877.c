#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **string;
    int curPos;
    int elements;
} Stack;

unsigned int fact(unsigned int n)
{
    unsigned int ret = 1;
    for(int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
} 

double combine(unsigned int n, unsigned int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

unsigned int numberOfCombinations(unsigned int numberOfElements)
{
    unsigned int ret = 0;
    for(int i = 1; i <= numberOfElements; i++) {
        ret += combine(numberOfElements, i);
    }
    return ret;
}

Stack *initStack(int size)
{
    Stack *s = malloc(sizeof(Stack));
    unsigned int combinations = numberOfCombinations(size);
    s->string = malloc((combinations + 1) * sizeof(char *));
    s->elements = combinations + 1;
    for(int i = 0; i < combinations + 1; i++) {
        s->string[i] = malloc(size + 1);
        memset(s->string[i], 0, size + 1);
    }
    s->curPos = 0;

    return s;
}

void destroyStack(Stack *s)
{
    for(int i = 0; i < s->elements; i++) {
        free(s->string[i]);
    }
    free(s);

}

void addToStack(Stack **s, char *string)
{
    if(strlen(string) == 0)
        return; 
    strcpy((*s)->string[(*s)->curPos], string);
    (*s)->curPos++;
}

char *substr(char *string, int pos)
{
    char *sub = malloc(strlen(string) - pos);
    int j = 0;
    for(int i = pos; i < strlen(string); i++, j++) {
        sub[j] = string[i];
    }
    sub[j] = '\0';

    return sub;
}

void recSubset(char *soFar, char *rest, Stack **s)
{
    if(strlen(rest) == 0) {
        addToStack(s, soFar);
    }
    else {
        char *nextSoFar = malloc(strlen(soFar) + 1);
        char *nextRest = substr(rest, 1);

        strcpy(nextSoFar, soFar);
        
        nextSoFar[strlen(soFar)] = rest[0];
        nextSoFar[strlen(soFar) + 1] = '\0';
        
        recSubset(nextSoFar, nextRest, s);
        recSubset(soFar, nextRest, s);
        
        free(nextSoFar);
        free(nextRest);
    }
}

Stack *Combinations(char *string)
{
    Stack *s = initStack(strlen(string));
    recSubset("", string, &s);
    return s;
}

char *readStringFromFile(FILE *stream, int numOfChars)
{
    char *string = malloc(numOfChars + 1);
    char c;
    int j = 0;
    for(; j < numOfChars;) {
        if((c = getc(stream)) != ' ' && c != '\n') {
            string[j] = c;
            j++;    
        }
    }
    string[j] = '\0';
    return string;
}

int main()
{
    FILE *in = fopen("cmlsc.in", "r");
    FILE *out = fopen("cmlsc.out", "w");
    int lenS1, lenS2;

    fscanf(in, "%d %d", &lenS1, &lenS2);

    char *string1 = readStringFromFile(in, lenS1);
    char *string2 = readStringFromFile(in, lenS2);

    Stack *combinations1 = Combinations(string1);
    Stack *combinations2 = Combinations(string2);

    int index = -1;
    int size = 0; 
    for(int i = 0; i < numberOfCombinations(strlen(string1)); i++) {
        for(int j = 0; j < numberOfCombinations(strlen(string2)); j++) {
            if(!strcmp(combinations1->string[i], combinations2->string[j])) {
                if(strlen(combinations1->string[i]) > size) {
                    size = strlen(combinations1->string[i]);
                    index = i;
                }
            }   
        }
    }

    fprintf(out, "%d\n", strlen(combinations1->string[index]));
    for(int i = 0; i < strlen(combinations1->string[index]); i++) {
        fprintf(out, "%c ", combinations1->string[index][i]);
    }

    destroyStack(combinations1);
    destroyStack(combinations2);

    free(string1);
    free(string2);
    
    fclose(in);
    fclose(out);
 
    return 0;
}
