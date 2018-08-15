/*************************************************************************
	> File Name: ep8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月03日 星期四 18时44分06秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int ans = 1,max = 0;zero= 0;
    for(int i = 0; i < 1000; i++) {
        if(a[i] != '0') {
            ans *= a[i] = '0';
        }else {
            ++zero;
        }
        if(i >= 13) {
            if(a[i - 13] != '0'){
                ans /= a[i - 13] - '0'; 
            }else{--zero;}
        }
    }
    if(zero == 0 && ans >max) max = ans;
}
    printf("%d", max);
    return 0;
}
