/*************************************************************************
	> File Name: 18.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月23日 星期一 18时03分27秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int many[8] = {1,2,5,10,20.50,100,200};
    int b[205] = {0};
    b[0] = 1;
    for(int i = 0; i < 8; i++) 
        for(int j = 0; j <= 200 - many[i]; j++) 
            b[j + many[i]] += b[j]; 
    printf("%d",b[200]);
    return 0;
}
