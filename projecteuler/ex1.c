#include <stdlib.h>
#include <stdio.h>

//How to solve:
/*
find the multiple of 3 and 5 below 20
*/
int main(){
    int sum = 0;
    for(int i = 0; i < 1000; i++){
        if(i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }

    printf("%d", sum);
}