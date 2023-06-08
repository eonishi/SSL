#include<stdio.h>

int main(){
    int s = 0, 
        t = 0, 
        nl= 0;

    for (int c = getchar(); c != EOF; c = getchar()){
        if (c == ' ')
            ++s;
        else if (c == '\t')
            ++t;
        else if (c == '\n')
            ++nl;
    }

    printf("Spaces: %d\nTabs: %d\nNewlines: %d\n", s, t, nl);
}