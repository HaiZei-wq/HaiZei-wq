/*************************************************************************
	> File Name: ep11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 22时02分47秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int ma, p;
    for(int i = 0; i<20; i++) {
        for(int j = 0; j < 20; j++) {
            for(int k = 0; k < 4; k++) {
                p = 1;
                for(int l = 0; l < 4; l++){
                    p *=num[i + l * direct[k][0]][j + l * direct[k][1]];
                }if(p > ma) ma = p;
            }
        }
    }
}
