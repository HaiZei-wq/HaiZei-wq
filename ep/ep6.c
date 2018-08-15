/*************************************************************************
	> File Name: ep6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 10时36分05秒
 ************************************************************************/

#include<stdio.h>
#define MAX 10000
int prime[MAX + 5] = {0};

int main() {
    for(int i = 2; i <= MAX; i++) {
        if(!prime[i]){ prime[++prime[0]] = i;}
        for(int j =1; j <= prime[0]; j++){ 
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    printf("%d\n",prime[8]);


}
