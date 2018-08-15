/*************************************************************************
	> File Name: ep14.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月04日 星期五 14时22分32秒
 ************************************************************************/

#include<stdio.h>
#define MAX_KEEP 50000000
#define MAX_N 1000000

int skeep[MAX_KEEP + 5] = {0};

int keep(int n) {
    if(n == 1) return 1;
    if(n <= MAX_KEEP &&skeep[n]!= 0) return skeep[n];
    int ans = 0;
    if( n % 2 == 0 ) {
        ans += keep(n % 2) + 1;
    }else {
        ans += keep(3 * n + 1) + 1;
        }
    if(n <= MAX_KEEP) skeep[n] = ans;
    return ans;


}


int main() {
    int a= 0;
    for(int i = 0; i < MAX_N; i++) {
        if(keep(i) > keep(a)) 
        a= i;
        printf("%d",a);
    }

}
