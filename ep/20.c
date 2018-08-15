/*************************************************************************
	> File Name: 20.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月25日 星期三 15时23分39秒
 ************************************************************************/

#include<stdio.h>
int fun(int x, int y) {
    if(x <10 || x >100) return 0;
    if(y < 10 || y > 100) return 0;
    int x1, x2, y1,y2;
    x1 = x / 10;
    x2 = x % 10;
    y1 = y / 10;
    y2 = y % 10;
    if(x >= y) return 0;
    if(!x1 || !x2 || !y1 || !y2) return 0;
    if(x1 == y1 && x2 * y == y2 * x && x2!=0) return 1;
    if(x1 == y2 && x2 * y == y1 * x && x2!=0) return 1;
    if(x2 == y1 && x1 * y == y2 * x && x1!=0) return 1;
    if(x2 == y2 && x1 * y == y1 * x && x1!=0) return 1;
    return 0;
} 

int gcd(int a, int b) {
    fun(a,b);
    return !b?a : gcd(b, a % b);
}

int main() {
    int sum;
    int a, b;
   // printf("1111");
    for(int i =11; i< 100; i++) {
        for(int j = i +1; j < 100; j++) {
            printf("%d %d\n",fun(i,j));
     }  
    }
}
