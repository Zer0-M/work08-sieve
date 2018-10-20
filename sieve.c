#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sieve.h"

int siv_of_E(int n){
    char bucket[150000];
    int nth_prime;
    for(int i=0;i<sizeof(bucket)/sizeof(char);i++){
        bucket[i]=0;
    }
    int count=0;
    for(int i=2;i<sizeof(bucket)/sizeof(char);i++){
        int prime;
        if(!bucket[i]){
            prime=i;
            count++;
            if(count==n){
                nth_prime=i;
            }
            for(int j=i+1;j<sizeof(bucket)/sizeof(char);j++){
                if(j%prime==0){
                    bucket[j]=1;
                }
            }
        }        
    }
    return nth_prime;
}
int main(){
    printf("%d\n",siv_of_E(10000));
}