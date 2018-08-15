/*************************************************************************
	> File Name: ep9.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月03日 星期四 18时59分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
    int flag = 1;
    int a, b ,c, e;
    for(int i = 1; i <1000&& flag;i++){
        for(int j = i +1; j <= 1000&& flag ; j++) {
            a = j * j - i * i;
            b = 2 * i * j;
            c = i * i + j * j;
            if( 1000 % (a + b + c) == 0 && 1000 / (a + b+ c) == 1){
           // e = pow(1000 / (a + b +c) ,3);
            printf("%d %d\n",i,j);
            printf("%d\n", a* b *c);
            flag = 0;
            
            }
        }
    }
}
