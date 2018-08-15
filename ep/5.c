/*************************************************************************
	> File Name: 5.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月15日 星期日 15时45分15秒
 ************************************************************************/

#include<stdio.h>

int facii(int n){
    int a[] = {0,1};
    int i = 0,x1 = 0,x2 = 1, x3 = 0;
    int p= 0;
    if(n<2)
         return a[n];
    for(i =2; i <= n+1; i++){
        x3 = x1 + x2;
        x1 = x2;
        x2 = x3;
       printf("%d\n",x3);
    
   if(x3% 2 == 0)
      p = x3 + p;  
    
    }return p;

}
int main(){
        int n,m;
        scanf("%d",&n);
        m = facii(n);
       printf("%d\n",m);

    }

