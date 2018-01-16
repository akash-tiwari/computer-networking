// ***     I AM SERVER   ***
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>


int main(){
	int sock, cli1, i, cli2;
	unsigned int len = 0, len1 = 0;
	struct sockaddr_in my, my2, client1, client2;
	char code = '3';	
	char buf[20];

	bzero((char *)&my, sizeof(my));
	my.sin_family  = AF_INET;
	my.sin_port = htons(5502);
	my.sin_addr.s_addr = INADDR_ANY;

        bzero((char *)&client1, sizeof(cli1));
        bzero((char *)&my2, sizeof(my2));
/*
	client2.sin_family = AF_INET;
	client2.sin_port = htons(5502);
	inet_pton(AF_INET, "172.20.22.121", &client2.sin_addr);
*/	
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock <0){
		perror("socket:");
		exit(1);
	}


	bind(sock, (struct sockaddr *)&my, sizeof(my));

	listen(sock, 5);


	cli1 = accept(sock, (struct sockaddr *)&client1, &len);
	if(cli1 < 0){
		perror("accept:");
		exit(1);
	}
	
	while(strcmp(buf, "bye") != 0){
		bzero(buf, sizeof(buf));
		if(len = recv(cli1, buf, sizeof(buf), 0) >0){
			printf("%s \n", buf);
			len = 0;
		}
		bzero(buf, sizeof(buf));
		scanf("%s", buf);
		send(cli1,  buf, sizeof(buf), 0);
		
	}
	

	close(sock);
	close(cli1);
	return 0;
}
