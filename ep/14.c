/*************************************************************************
	> File Name: 14.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 14时59分53秒
 ************************************************************************/

#include<stdio.h>
#include"14.h"
int main(){
int dir[4][2] = {0,1,1,1,1,0,1,-1};
int ans = 0;
for(int i = 0; i < 20; i++) {
    for(int j = 0; j < 20;j++){
        for(int k = 0; k < 4; k++){
            int p =1;
            for(int l = 0; l < 4; l++){
                int x = i + dir[k][0] * l;
                int y = i + dir[k][1] * l;
                if(x < 0 || x >=20) break;
                if(y < 0 || y >= 20) break;
                p *=a[x][y];
            } 
        }if(p > ans) ans = p;
    }
}
printf("%d\n",ans);
return 0;
}
