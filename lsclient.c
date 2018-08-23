/*************************************************************************
	> File Name: lsclient.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月11日 星期一 18时52分42秒
 ************************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#define SERVER_PORT 6666 /* 客户机连接远程主机的端口 */ 
#define MAXDATASIZE 100 /* 每次可以接收的最大字节 */ 
#define SERVER_IP "192.168.1.66" /* 服务器的IP地址 */

int main()
{ 
    int sockfd, numbytes; 
    char buf[MAXDATASIZE]; 
    struct sockaddr_in server_addr;

    printf("\n======================client initialization======================\n"); 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    { 
        perror("socket"); 
        exit(1); 
    } 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(SERVER_PORT); 
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    bzero(&(server_addr.sin_zero),sizeof(server_addr.sin_zero)); 

    if (connect(sockfd, (struct sockaddr *)&server_addr,sizeof(struct sockaddr_in)) == -1) 
    { 
        perror("connect");
        exit(1); 
    }

    //循环输入文字
    while(1)
    {        
        bzero(buf,MAXDATASIZE);
        printf("\nBegin receive...\n");
        if ((numbytes=recv(sockfd, buf, MAXDATASIZE, 0)) == -1)        
        { 
            perror("recv");
            exit(1); 
        }
        else if (numbytes > 0)        
        {
            int len, bytes_sent;
            buf[numbytes] = '\0';
            printf("Received: %s\n",buf);
            
            printf("Send:");
            char *msg;
            scanf("%s",msg);            
            len = strlen(msg);

            //发送至服务器
            if(send(sockfd,msg,len,0) == -1)
            { 
                perror("send error");
            }
        }
        else
        {
            //numbytes=0，表示socket已断开
            printf("soket end!\n");
        }
        
    }

    close(sockfd); 
    return 0;
}
