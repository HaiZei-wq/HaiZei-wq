/*************************************************************************
	> File Name: ep12.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 16时17分12秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000
int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0};
int mnum[MAX_N + 5] = {0};

void init() {
    for(int i = 2; i <=MAX_N; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
           
        }
        for(int j = 1; j <=prime[0]; j++) {
            if(prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                //int knum = 0, pre_i = i;
                //while(pre_i % prime[j] == 0 ) pre_i /=prime[j], knum++;
                dnum[prime[j] * i] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                mnum[i * prime[j]] = mnum[i] + 1;
                break;
            }else {
                mnum[i * prime[j]] = 1;
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
            }
        }
    }
    return ;
}

int main() {
    init();
    int n = 2;
    while(1) {
        int total = 0;
        if(n & 1) {
            total = dnum[n] * dnum[(n + 1) >> 1];
        }else {
            total = dnum[n / 2] * dnum[n + 1];
        }
        n++;
        if(total >= 500)
        break;
    }
    printf("%d",n * ( n + 1 ) / 2);


    return 0;
}
