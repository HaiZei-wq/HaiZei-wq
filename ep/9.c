/*************************************************************************
	> File Name: 9.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月18日 星期三 19时22分10秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX 2540160
int is_ok(int n) {
    int res = 1;
    int aa = 0;
    int sum = n;
    int tmp = 0;
    while(n){
        int m = n % 10;
        n /= 10;
        for(int i = 2; i <= m; i++){
            
            res = res * i;
            aa = res;
        }tmp += aa;
        res = 1;
    }return sum == tmp;
}
int main(){
    int t = 0;
    for(int i =2; i <= MAX; i++){
        if(is_ok(i))
        t += i;
    }printf("%d\n",t);
    return 0;
}
