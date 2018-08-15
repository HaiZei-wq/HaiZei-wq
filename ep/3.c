/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月11日 星期三 19时47分35秒
 ************************************************************************/

#include<stdio.h>
int main(){
    char a[100] = "  hello   word      h     haizie  ";
    char b[20] = {0};
    int offset = 0;
   while(sscanf(a + offset, "%s", b) != EOF) {
       while(a[offset] == ' '){
           ++offset;
        }
        int read = printf("%s\n", b);
       // printf("%d\n",offset);
        offset +=read;

    }
    return 0;
}
