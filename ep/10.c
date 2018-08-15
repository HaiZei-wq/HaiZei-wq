/*************************************************************************
	> File Name: 10.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月18日 星期三 20时17分06秒
 ************************************************************************/

#include<stdio.h>
int num(int n, int base) {
    int tmp = n;
    int x= 0;
    while(n) {
        x = x * base + n % base;
        n /=base;

    }return x == tmp;
}
int main() {
    int sum = 0;
    for(int i = 1; i <=1000000; i+=2){
        if(num(i,2) && num(i,10)){
            sum += i;  
        
        }
    }printf("%d\n",sum);
        return 0;

    
}
