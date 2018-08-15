/*************************************************************************
	> File Name: ep24b.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 14时46分17秒
 ************************************************************************/

#include<stdio.h>

#define MAX 1000000
#define MAX_M 10

int a[MAX_M] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(){
    int n = MAX - 1, max= 1, ind = 0;
    while(max <= n && ind < 10) {
        ind++;
        max *= ind;
    }
    max /= ind;
    for(int i = MAX_M - ind; i < MAX_M && n; i++) {
        --ind;
        int j = i + 1, k;
        while(n >= max && j <MAX_M) {
            k = a[i];
            a[i] = a[j];
            a[j] = k;
            n -= max;
            ++j;
        }
        max /= ind;
    }
    for(int i = 0; i< MAX_M; i++) {
        printf("%d",a[i]);
    }
    return 0;
}
