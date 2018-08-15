/*************************************************************************
	> File Name: 15.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 16时22分16秒
 ************************************************************************/

#include<stdio.h>
#define MAX_KEEP 5000000
#define MAX 1000000
int keep[5000005] = {0};
int get_chain_len(long x) {
    if(x == 1) return 1;
    if(x <= MAX_KEEP && keep[x]){
        return keep[x];
    }
    int ans = 0;
    if(x % 2 == 0) {
        ans =get_chain_len(x /2) + 1;
    }else{
        ans = get_chain_len(3 * x + 1) + 1;
    }
    if(x < MAX_KEEP) {
        keep[x] = ans;
    }
    return ans;
}
int main() {
    int ans = 0;
    int ans_len = 0;
    for(int i = 1; i <MAX; i++) {
        int tmp_len = get_chain_len(i);
        if(tmp_len > ans_len){
            ans_len = tmp_len;
            ans = i;
        }
    }
    printf("%d %d\n",ans, ans_len);
    return 0;
}
