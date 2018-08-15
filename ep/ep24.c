/*************************************************************************
	> File Name: ep24.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 19时37分49秒
 ************************************************************************/

#include<stdio.h>

int fun(int n) {
    if(n == 0) return 1;
    return n* fun(n - 1);
}

int get_num(int n,int k ,int *num,int delta) {
      int rank =  k / delta + 1, now = 0;
    for(int i = 0; i < n; i++) {
        now +=!(num[i]);  //第i个没有被标记过得数字
        if(now == rank) return i;
    }
    return -1;
}


int main() {
   int n, k;
   scanf("%d %d",&n,&k);
    int num[100] = {0}, delta = fun(n - 1); 
    k = k - 1;
    for(int i = 0; i < n; i++) {
        int digit = get_num(n, k,num, delta);
        printf("%d",digit);
        num[digit] = 1;
        k %= delta;
        if(i == n - 1) break;
        delta /= (n - 1 - i);
    }

    return 0;
}
