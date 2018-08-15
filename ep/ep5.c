/*************************************************************************
	> File Name: ep5.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 10时35分20秒
 ************************************************************************/

#include<stdio.h>

int gcd(int a,int b) {
    return !b ? a : gcd(b, a % b); 
}

int main() {
    int ans = 1;
    for(int i = 1; i <= 20 ;i++) {
        ans*= i / gcd(i, ans);
    }
    printf("%d",ans);

    return 0;
}
