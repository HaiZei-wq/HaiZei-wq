/*************************************************************************
	> File Name: ep10.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 21时46分51秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
# define MAX 2000000

int prime[MAX + 5] = {0};
int sum[MAX + 5] = {0};

int main() {
    int64_t sum = 0;
    for(int64_t i = 2; i <= MAX; i++) {
        if(!prime[i]){ prime[++prime[0]] = i; sum += i;}
        for(int64_t j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    printf("%"PRId64"\n",sum);
}
