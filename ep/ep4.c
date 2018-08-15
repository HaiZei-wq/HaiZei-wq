/*************************************************************************
	> File Name: ep4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 17时38分39秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int check(int n) {
    int b = n,x = 0;
    while(n) {
        x = x * 10 + n % 10;
        n /= 10;
    }
    return b == x;
}

int main() {
    int sum = 0;
    for(int i =100;i < 1000; i++) {
        for(int j = 100; j < 1000; j++) { 
            if(check(i * j) && i * j > sum) 
            sum = i*j;
    }
}
    printf("%d",sum);
}
