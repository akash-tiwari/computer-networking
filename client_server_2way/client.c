//  ***  I am client 1  ***
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/wait.h>

int main(){
	int sock, len = 0, p, cli, status, code, j;
	struct sockaddr_in my, my2, ser, client;
	char *host, buf[20], s[] = "172.20.22.121", req[10], i = '3';

	bzero(&my, sizeof(my));
	bzero(&my2, sizeof(my2));
	bzero(&ser, sizeof(ser));
        bzero(&client, sizeof(client));

	my.sin_port = htons(5502);
	my.sin_family = AF_INET;
	my.sin_addr.s_addr = INADDR_ANY;		

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock <  0){
		perror("socket:");
		exit(1);
	}
	bind(sock, (struct sockaddr *)&my, sizeof(my));
	
	if(connect(sock, (struct sockaddr *)&my, sizeof(my)) < 0){
		perror("connect:");
		close(sock);
		exit(1);
	}
	while(strcmp(req, "bye") != 0){
		scanf("%s",req);
		strcat(buf, req);
		send(sock,  buf, sizeof(buf), 0);
		len = 0;
		if(len = recv(sock, buf, sizeof(buf), 0) > 0){
			printf(" %s \n", buf);
			len = 0;
		}
		scanf("%s",req);
                strcat(buf, req); 
		send(sock,  buf, sizeof(buf), 0);
   
	}
//	printf("buffer is being sent\n");
	close(sock);
	close(cli);
	return 0;
}
