/*************************************************************************
	> File Name: KMP.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月02日 星期四 20时35分33秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int BF(const char *text, const char *pattern, int *p_cnt) {
    #define cnt (*p_cnt)
    int len1 = strlen(text);
    int len2 = strlen(pattern);
    for(int i = 0; i < len1 - len2 + 1; i++, cnt++) {
        int flag = 1;
        for(int j = 0; pattern[j] && flag; j++,cnt++) {
            if(text[i + j] == pattern[j]) continue;
            flag = 0;
        }
        if(flag) return 1;
    }
    #undef cnt
    return 0;
}

int KMP(const char *text, const char *pattern, int *p_cnt) {
    #define cnt (*p_cnt)
    int len1 = strlen(text);
    int len2 = strlen(pattern);
    int *next = (int *)malloc(sizeof(int) * len2);
    int j = -1; 
    next[0] = -1;
    for(int i = 1; i < len2; i++,cnt++) {
        int j = next[i - 1];
        while(j != -1 && pattern[j + 1] != pattern[i]) j = next[j], cnt++;
        if(pattern[j + 1] == pattern[i]) {
            j += 1;
        }
        next[i] = j;
    }
    j = -1;
    for(int i = 0; text[i]; i++,cnt++) {
        while(j != -1 && pattern[j + 1] != text[i]) j = next[j],cnt++;
        if(pattern[j + 1] == text[i]) j += 1;
        if(pattern[j + 1] == 0) return 0;
    }
    #undef cnt
    return 0;
}




int main() {
    char str1[] = "hello world";
    int cnt = 0;
    printf("BF(%s, %s) = %d\n", str1, "wor", BF(str1, "wor", &cnt));
    printf("BF : %d\n", cnt);
    cnt = 0;
    printf("KMP(%s, %s) = %d\n", str1, "wor", KMP(str1, "wor", &cnt));
    printf("KMP : %d\n", cnt);
    return 0;
}
