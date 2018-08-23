/*************************************************************************
	> File Name: lsserver.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月11日 星期一 19时13分43秒
 ************************************************************************/

#include<stdio.h>
#include"head.h"
#include<arpa/inet.h>
#define DBG(fmt, args...) printf(fmt, ##args)

#define MAX_SIZE 1024


int send_response(int sockfd, int rq) {
    if(send(sockfd,&rq,sizeof(rq), 0) <= 0) {
        perror("error");
        return -1;
    }
    return 0;
}

int recv_response(int sockfd) {
    int res_recv;
    if((recv(sockfd,&res_recv,sizeof(int), 0)) <= 0) {
        return -1;
    }
    return res_recv;
}

char data_dir[50]="/tmp";

int generate_name(int code, char *logname, char *log_dir) {
    strcpy(logname, log_dir);
    switch (code) {
        case 100:
            strcat(logname, "/data.log");
            break;
        case 101:
            strcat(logname,"/ps.log");
            break;
        case 102:
            strcat(logname, "./man.log");
            break;
        default:
            break;
    }
    return 0;
}

int master_get(int data_sock, int reqcode, char *client) {
    char data[MAX_SIZE];
    int size;
    char arg[MAX_SIZE] = {0};
    char logdir[100] = {0};
    strcpy(logdir,data_dir);
    strcpy(logdir,"/");
    strcpy(logdir,client);
    mkdir(logdir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    generate_name(reqcode, arg, logdir);

    FILE *fd = fopen(arg, "a+");

    while((size = recv(data_sock, data, MAX_SIZE, 0)) > 0) {
        fwrite(data, 1, size,fd);
    }

    fclose(fd);

    DBG("write massage to file %s\n",arg);

    return 0;
}

int main(int argc, char *argv[]) {
    int a= 0;
    int server_listen, socketfd, port, pid;
    if(argc != 2){
        printf("Usage : ./lsclient prot\n");
        exit(0);
    } 

    port = atoi(argv[1]);

    if((server_listen = socket_create(port)) < 0) {
        printf("error creating server_listen socket");
        exit(1);
    }

    while(1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        if((socketfd = accept(server_listen, (struct sockaddr*) &client_addr, &len)) < 0)
        break;

        struct sockaddr_in peer;
        socklen_t peer_len = sizeof(struct sockaddr_in);
        bzero(&peer,sizeof(struct sockaddr_in));
        getpeername(socketfd, (struct sockaddr *)&peer,&peer_len);
        char buff_peer[64] = {'\0'};
        inet_ntop(AF_INET, (void*)&peer.sin_addr, buff_peer, 63);
        
        if((pid = fork()) < 0)
              printf("error forking child process");
              perror("fork");
        if(pid == 0) {
                  close(server_listen);
                  int retcode = recv_response(socketfd);
                  DBG("recive dode from %s retcode = %d\n",buff_peer,retcode);
                  fflush(stdout);
                  send_response(socketfd, 1);

                  master_get(socketfd, retcode, buff_peer);
                  close(socketfd);
        }
        printf("par\n");
        close(socketfd);


    }
              return 0;
}
