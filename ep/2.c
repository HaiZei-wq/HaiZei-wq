/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月11日 星期三 18时09分13秒
 ************************************************************************/

#include<stdio.h>
int strncmp(char *arr1, char *arr2,int n){
    int i =0;
    for( i =0; i< n; ++i){
        if(arr1[i]!= arr2[i]){
            return arr1[i] - arr2[i];
        }
    }
}
int strncpy(char *arr1, char *arr2,int n){
    int i = 0;
    for(i = 0; i < n; ++i)
        if(arr1[i] = arr2[i]){
            return 2;
        }else{
            return 1;
        }

    }
int main(){
    char s1[] = "aelpu";
    char s2[] = "haulo";
    int aa = strncmp(s1,s2,2);
    int bb = strncpy(s1,s2,2);
    printf("%d\n",aa);
    printf("%d\n",bb);
    return 0;
}
