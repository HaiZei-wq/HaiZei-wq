/*************************************************************************
	> File Name: ep3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 17时29分52秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

#define MAX 600851475143

int32_t main() {
    int64_t num = MAX;
    int64_t prime;
    for(int64_t i = 2; i * i <= MAX; i++) {
        if(num % i == 0) {
            num /= i;
            prime = i;
        }
    }
    if(num != 1) prime = num;
    printf("%"PRId64"\n",prime);
    return 0;
}
