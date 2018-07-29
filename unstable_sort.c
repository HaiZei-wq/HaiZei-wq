/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 09时52分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


#define TEST(n ,func) {\
    int num[n] = {0};\
    printf("[");\
    for(int i = 0; i < n; i++) {\
        num[i] = rand() % 100;\
        printf("%d ", num[i]);\
        }\
        printf("]\n");\
        func;\
        output(num, n, #func);\
}

#define swap(a,b) {\
    __typeof(a) temp;\
    temp = a; a= b; b = temp;\
}

void ungarded_insert_sort(int *num, int n);

void select_sort(int *num, int n){
    for(int i = 0;  i< n- 1; i++) {
        int ind = i;
        for(int j = i + 1; j < n; j++) {
            if(num[j] < num[ind])  ind = j;
        }
        swap(num[i], num[ind]);
    }
}

void quick_sort(int *num, int l, int r) {
    while(r - l >= 2) {
        int x = l, y = r, z = num[rand() % (r - l + 1) + l];
        do {
            while(num[x] < z) ++x;
            while(num[y] > z) --y;
            if(x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while(x <= y);
        quick_sort(num, l, y);
        l = x;
    }
    ungarded_insert_sort(num + l, r - l + 1);
    return ;
}

void output(int *num, int n, const char *str) {
    printf("%s = [", str);
    for(int i = 0; i < n; i++) {
        printf("%d ",num[i]);
    }
    printf("]\n");

}

void ungarded_insert_sort(int *num, int n) {
    int ind = 0;
    for(int i= 1 ; i < n; i++) {
        if(num[i] < num[ind]) ind = i;
    }
    swap(num[ind], num[0]);
    for(int i = 2 ; i < n; i++) {
        int j = i;
        while(num[j] < num[j - 1]) {
            swap(num[j], num[j- 1]);
            j--;
        }
    }
    return ;
}



int main() {
    srand(time(0));
    TEST(30, select_sort(num,30));
    TEST(30, quick_sort(num,0, 29));
    return 0;
}
