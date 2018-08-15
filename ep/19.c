/*************************************************************************
	> File Name: 19.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月23日 星期一 19时22分39秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int num[10] = {0};
int dit(int x, int y) {
    int ans = 0;
    ans += floor(log10(x)) + 1;
    ans += floor(log10(y)) + 1;
    ans += floor(log10(x * y)) +1;
    return ans;
}
int once(int x,int *num ) {
    while(x){
    if (x % 10 == 0) return 0;
    if(num[x % 10]) return 0;
    num[x % 10] = 1;
    x /= 10;
    }
    return 0;
}
int ispan(int x, int y) {
    int num[10] = {0};
    if(once(x,num) && once(y,num) && once(x * y, num)){
        return 1;
    }
}



int main() {
    int sum = 0;
    int temp[10000] = {0};
    for(int i = 1; i < 100; i++) {
        for(int j = 100; ; j++) {
            //sum = dit(i,j);
            if(dit(i , j) < 9) continue;
            else if(dit(i,j) > 9) break;
        
        if(ispan(i,j) && !temp[i * j]) {
            sum += i * j;
            temp[i * j] = 1;
            
        }
        }
    }
    printf("%d\n",sum);





    return 0;
}
