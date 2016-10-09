#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socketvar.h>
#include <netinet/in.h>
#include <string.h>

#define TRUE 1


int main()
{
    int client_fd;

    struct sockaddr_in cliadd;

    client_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    cliadd.sin_family = AF_INET;
    cliadd.sin_port = 8000;

    connect(client_fd,(struct sockaddr*)&cliadd,sizeof(cliadd));

    char recvline[4096],sendline[4096];

    while(TRUE){
        fgets(sendline,4096,stdin);

        if(strcmp(sendline,"bye") == 0){
            break;

        }

        int errono;

        if( errono = send(client_fd,sendline,strlen(sendline),0) < 0){


        }
        printf("send msg error: %s (errno: %d ) \n",strerror(errono),errono);

    }






    printf("Hello world!\n");
    return 0;
}
