/*************************************************************************
	> File Name: 6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月15日 星期日 16时45分56秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define NUM 600851475143
int main(){
    long n = NUM;
    int max= 0;
    for(long i =2; i *i <= NUM; ++i){
        while(n %i==0){
            n /=i;
            max = i;
        } 
    }
    if(n!=1) max = n;
    printf("%d\n",max);
    return 0;

}
