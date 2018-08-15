/*************************************************************************
	> File Name: 7.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月15日 星期日 18时31分35秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a % b);
}

int main(){
    long ans = 1;
    for(int i =1; i<= 20; ++i){
        ans *=i / gcd(i,ans);
    }
    printf("%ld\n",ans);
    return 0;
}
