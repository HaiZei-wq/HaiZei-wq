/*************************************************************************
	> File Name: ep25.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月07日 星期一 15时34分42秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int sum = 1, len = 2;
    int m;
    while(len <= 501) {
        m = 2 * len - 1;
        sum += 4 * m * m - 6 * m + 6; 
        len++;
    }
    printf("%d",sum);
    return 0;
}
