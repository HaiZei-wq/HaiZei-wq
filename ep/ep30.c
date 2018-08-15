/*************************************************************************
	> File Name: ep30.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月07日 星期一 18时46分36秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<inttypes.h>
#define MAX 354294

int32_t fun(int n) {
    int32_t sum = 0, x= n;
    while(n) {
        sum +=(int32_t)pow(n % 10, 5);
        n /= 10;
    } 
        return sum == x;
}

int main() {
    int32_t sum = 0;
    for(int32_t i = 2 ; i <= MAX; i++) {
        if(fun(i))
        sum += i;
    }
    printf("%d\n",sum);
}
