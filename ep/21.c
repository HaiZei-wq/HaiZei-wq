/*************************************************************************
	> File Name: 21.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月25日 星期三 18时28分09秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX 1000000
int prime[MAX + 5] = {0};
int prime_num[MAX] = {0};


int iscir(int n) {
    if(prime[n] != 0) return 0;
    int x = n;
    int h,j;
    h = pow(10, floor(log10(n)));
    j = floor(log10(n));
    for(int i = 0; i < j; i++) {
        x = x/ 10 +(x %10) * h;
        if(prime[x] != 0) return 0;
    }
    return 1;
}
int main() {
    int k = 0;
    for(int i = 2; i <= MAX; i++) {
        if(!prime[i]) prime_num[++prime_num[0]] = i;
        for(int j = 1; j <= prime_num[0]; j++) {
            if(i * prime_num[j] > MAX) break;
            prime[i * prime_num[j]] = 1;
            if(i % prime_num[j] == 0) break;
        }
    }
    for(int i = 1; i <= prime_num[0]; i++) {
        if(iscir(prime_num[i]))
        printf("%d\n",prime_num[i]);
        k++;
    }
    printf("%d",k);
}

