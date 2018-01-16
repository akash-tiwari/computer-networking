#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
	int sock, cli, i;
	unsigned int len = 0, len1 = 0;
	struct sockaddr_in my, client;
	char buf[50];	

	bzero((char *)&my, sizeof(my));
	my.sin_family  = AF_INET;
	my.sin_port = htons(5502);
	my.sin_addr.s_addr = INADDR_ANY;

        bzero((char *)&client, sizeof(cli));


	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock <0){
		perror("socket:");
		exit(1);
	}
	if(bind(sock, (struct sockaddr *)&my, sizeof(my)) < 0 ){
		perror("bind:");
		exit(1);
	}
	listen(sock, 5);
	cli = accept(sock, (struct sockaddr *)&client, &len);
	if(cli < 0){
		perror("accept:");
		exit(1);
	}
	while(1){
		len = recv(cli, buf, sizeof(buf), 0);
			if(strcmp(buf ,"bye") == 0){
				break;
			}
			for(i = 0; i< 50 && buf[i] != '\0'; i++){
				printf("%c",buf[i]);
			}
			printf("\n");
	}
	close(sock);
	close(cli);
	return 0;
}
