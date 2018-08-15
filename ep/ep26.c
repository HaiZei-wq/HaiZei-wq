/*************************************************************************
	> File Name: ep26.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 09时07分39秒
 ************************************************************************/

#include<stdio.h>

int fun(int d) {
    int first_ind[1000] = {0};
    int y = 1, ind = 1;
    do{
        first_ind[y] = (ind++);
        y = (y * 10) % d;
    }while(y && first_ind[y] == 0);
    if(y == 0) return 0;
    return ind - first_ind[y];
}




int main() {
    int ans,temp;
    int max_lenth = 0;
    for(int i = 2; i < 1000; i++) {
        temp = fun(i);
        if(temp > max_lenth) {
            ans = i;
            max_lenth = i;
        }
    }
    printf("%d",max_lenth);
    return 0;
}
