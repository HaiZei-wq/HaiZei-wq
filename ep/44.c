/*************************************************************************
	> File Name: 44.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 10时31分39秒
 ************************************************************************/

#include<stdio.h>
#define MAX 3000
long arr[MAX + 5] = {0};


int fun (int n) {
    return (n *(3 * n - 1)) >> 1;
}


int func(int n) {
   // int range = a;
   // if(a < 0) range = -a;
    int left = 1, right = MAX - 1; 
    int mid,t;
   // mid = (left + right) >> 1;
    while(left <= right) {
    mid = (left + right) >> 1;
       // t = fun(mid);
        if(fun(mid) == n) return 1; 
        else if(fun(mid) < n) {
        left = mid + 1;
    }else if(fun(mid) > n) {
        right = mid - 1;
    }
      // mid = (left + right) >> 1;
    }

    return 0;
}


int main() {
    int n, m;
    for(int  n = 1; n < MAX; n++) {
        arr[n] = fun(n);
    }
    int  min  = 9999999;
    for(int i = 2; i< MAX; ++i) {
       //if(arr[i + 1] - arr[i] > min) break;
        for(int j = i + 1; j <= MAX ; j++) {
            if(arr[j] - arr[i] > min) break;
             n = arr[j] - arr[i];
             m = arr[i] + arr[j];
            if(func(n) && func(m) && arr[j - arr[i] < min]) {
               // if(min > arr[j] - arr[i])
                min = arr[j] - arr[i];
                //printf("%d\n",min);
               // return 0;
            }
        }
    }
    printf("%d\n",min);
    return 0;

}
