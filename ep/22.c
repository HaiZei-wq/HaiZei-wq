/*************************************************************************
	> File Name: 22.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月25日 星期三 19时57分11秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int ispan(int n, int *num) {
    while (n) {
        if(n % 10 == 0) return 0;
        if(num[n % 10] == 0) return 0;
        num[n % 10]  = 1;
        n /= 10;
        
    }
    return 1;
}
int fun(int x) {
    int num[10] = {0};
    int temp_ans = 0;
    int value;
    int digits;
    for(int i = 1; ; i++) {
        int t = x * i;
        if(!ispan(t,num)) return 0;
        value = pow(10, floor(log10(t)) + 1);
        temp_ans = temp_ans * value + t;
        digits = floor(log10(temp_ans)) + 1;
        if(digits > 9) return 0;
        if(digits = 9) break;
    }
    return temp_ans;
}
int main(){
    int num,max_num = 0;
    for(int i = 1; i<= 10000; i++) {
        //if(!fun(i,num)) continue;
        num = fun(i);
        if(num > max_num) {
        max_num = num;
        printf("%d\n",i);
    }
    printf("%d\n",max_num);
    return 0;
}
}
