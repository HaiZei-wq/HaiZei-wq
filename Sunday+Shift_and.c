/*************************************************************************
	> File Name: string.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月04日 星期六 11时54分27秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TEST(func) {\
    printf("%s = %d\n", #func, func);\
}

typedef struct shift {
    
}shift;


int sunday(const char *text, const char *pattern) {
    int len = strlen(pattern),len2 = strlen(text);
    int ind[127] = {0};
    for(int i = 0; i < 127; i++) ind[i] = len + 1;
    for(int i = 0; pattern[i]; i++) ind[pattern[i]] = len - i;
    for(int i = 0; i <= len2 - len;  ) {
        int j = 0;
        for(; j < len; j++) {
            if(pattern[j] != text[i + j]) break;
        }
        if(j == len) return 1;
        i += ind[text[i + len]];
    }
    return 0;
}


int shift_and(const char *text, const char *pattern) {
    int len = strlen(pattern);
    int **d = (int **)calloc(sizeof(int *), 128);
    for(int i = 0; i < 128; i++) d[i] = calloc(sizeof(int), len);
    for(int n = 0; pattern[n]; n++)  d[pattern[n]][n] = 1;
    int *p = (int *)calloc(sizeof(int), len);
    
    for(int i = 0; text[i]; i++) {
        for(int j = len - 1; j >= 0; j--) {
            p[j + 1] = p[j];
        }
        p[0] = 1;
        for(int j = 0; j < len; j++) {
            if(p[j] == 1 && d[text[i]][j] == 1) {
                p[j] = 1;
            }else {
                p[j] = 0;
            }
        }
        if(p[len - 1] == 1) return 1;
    }
    for(int i = 0; i < 128; i++) free(d[i]);
    free(d);
    free(p);
    return 0;
}

int main() {
    TEST(sunday("helloworld", "hello"));
    TEST(shift_and("hello wordldddsafsfafadasadsfasdf", "helloadsfafafasdfas"));
    TEST(shift_and("hello wordld", "he"));
    TEST(shift_and("hello wordld", "weo"));
    TEST(shift_and("hello wordld", "wr"));
    return 0;
}
