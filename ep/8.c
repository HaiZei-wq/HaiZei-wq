/*************************************************************************
	> File Name: 8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月18日 星期三 19时02分24秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<inttypes.h>
#define MAX_N 354294
int is_ok(int n) {
    int tmp = n;
    int sum = 0;
    while(n) {
        sum += pow(n % 10 ,5);
        n /= 10;
    }
    return tmp == sum;
}
int main(){
    int sum = 0;
    for(int i =2; i < MAX_N; i++) {
        if(is_ok(i)) {
            sum += i;
            //printf("%d\n",i);
        }
    }printf("%d\n",sum);
    return 0;

}
