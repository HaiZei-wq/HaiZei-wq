/*************************************************************************
	> File Name: 43.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 10时17分16秒
 ************************************************************************/

#include<stdio.h>

int isinter(int *a) {
    if(a[0] == 0) return 0;
    int p[7] = {2,3,5,7,11,13,17}, j = 0;
    int num = a[0],ret = a[0];
    for(int i = 1; i< 10; i++) {
        ret = ret * 10 + a[i];
        num = num * 10 + a[i];
        if(i < 3) continue;
        num -= 1000 * a[i - 3];
        if(num % p[j++]) return 0;
    }
    return ret;
}
int main() {
    int a[10] = {0};
    for(int i = 0; i < 10; i++) {
        a[i] = i;
    }
    int sum = 0,temp;
    do{
        sum += isinter(a);
    }
    while(next_permutation(a, a+ 10));
    printf("%"PRId64"\n",sum);
    return 0 ;
}
