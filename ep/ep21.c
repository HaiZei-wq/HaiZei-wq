/*************************************************************************
	> File Name: eo21.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 14时14分24秒
 ************************************************************************/

#include<stdio.h>

#define MAX 10000

int prime[MAX + 5] = {0};
int dnum[MAX + 5] = {0};
int mnum[MAX + 5] = {0};

void init() {
    for(int i = 2; i <= MAX; i++) {
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = i + 1;
            mnum[i] = i * i - 1;
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                mnum[i * prime[j]] = (mnum[i] + 1) * prime[j] - 1;
                dnum[i * prime[j]] = dnum[i] * mnum[i * prime[j]] / mnum[i];
                break;
            }else{
                mnum[i * prime[j]] = mnum[prime[j]];
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
}
int main() {
    init();
    for(int i = 2; i< MAX; i++) {
        dnum[i] -= i;
    }
    int res = 0;
    for(int i = 2;i <= MAX; i++) {
        if(dnum[i] == i) continue;
        if(dnum[i] > MAX) continue;
        if(dnum[dnum[i]] == i)
        res += i;
    }
    printf("%d",res);
    return 0;

}
