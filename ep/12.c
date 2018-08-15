/*************************************************************************
	> File Name: 12.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 09时01分11秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX 400000
int main() {
    int p[MAX + 5] = {0};
    //int max = 20005;
    //int n;
    for(int i = 2; i <= MAX; i++){
        if(!p[i]) p[++p[0]] = i;
        for(int j = 1; j<= p[0]; j++){
            if(i * p[j] > MAX) break;
            p[i * p[j]] = 1;
            if(i % p[j] == 0) break;
        }
    }
   // while(scanf("%d",&n)!=EOF){
        printf("%d\n",p[20000]);
    
    return 0;
}
