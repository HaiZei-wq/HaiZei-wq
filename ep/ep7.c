/*************************************************************************
	> File Name: ep7.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月03日 星期四 18时03分46秒
 ************************************************************************/

#include<stdio.h>
#define MAX 100000

int prime[MAX + 5] = {0};

int main() {
    for(int i = 2; i <= MAX; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }int n;
    while(scanf("%d",&n) !=EOF) {
        
    
    printf("%d",prime[n]);

}
}
