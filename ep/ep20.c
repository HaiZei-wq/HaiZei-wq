/*************************************************************************
	> File Name: ep20.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 18时53分38秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int arr[200] = {0};
    arr[0] = arr[1] = 1;
    for(int i = 1; i < 100; i++) {
        for(int j = 1; j <= arr[0]; j++) arr[j] *=i;
        for(int j = 1; j <= arr[0]; j++) {
            if(arr[j] < 10) continue;
            arr[j + 1] += arr[j] / 10;
            arr[j] %= 10;
            arr[0] += (j == arr[0]);
        
    }

}
    int ans = 0;
    for(int i = 1; i <= arr[0]; i++) {
        ans+=arr[i];
    }
    printf("%d",ans);
    return 0;
}




