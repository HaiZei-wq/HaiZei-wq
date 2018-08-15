/*************************************************************************
	> File Name: 45.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 14时09分58秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int pen(int64_t n) {
    return n * (3 * n - 1) / 2;
}
int64_t power(int64_t x) {
    return x * x;
}


int is_pen(int64_t n , int64_t (*func)(int64_t)) {
    int64_t head = 1,tail = n,mid;
    while(head <= tail) {
        mid = head + tail >> 1;
        int64_t value = func(mid);
        if(value == n) return 1;
        if(value > n)
        tail = mid - 1;
        else head = mid + 1;
    }
    return 0;
}
int main() {
    int64_t n = 144;
    while(!is_pen(n * (2 * n - 1) , pen)) n++;
    printf("%"PRId64"\n",n * (2 * n - 1));
    printf("%d",is_pen(5, power));
    printf("%d",is_pen(9, power));
    return 0;
}
