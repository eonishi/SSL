#include<stdio.h>

int main(){
    for (int c = getchar(); c != EOF; c = getchar())
        if (c == '\t')
            printf("\\t ");
        else if (c == '\b')
            printf("\\b ");
        else if (c == '\\')
            printf("\\\\ ");
        else
            putchar(c);
}