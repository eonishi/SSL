#include<stdio.h>
#include<assert.h>

int main(){
    int c;
    c = (getchar() != EOF);
    assert(c == 0 || c == 1);
}