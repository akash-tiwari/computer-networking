//  ***  I am client   ***
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){
	int sock, len = 0;
	struct sockaddr_in my, ser;
//	struct hostent *h;
	char *host, buff[50], s[] = "172.20.22.121";
	
//	h = gethostbyname(host);
/*	if(h){
		perror("host error:");
		exit(1);
	}*/
	bzero(buff,  sizeof(buff));
	bzero(&my, sizeof(my));
	bzero(&ser, sizeof(ser));
	my.sin_port = htons(5502);
	my.sin_family = AF_INET;
	my.sin_addr.s_addr = INADDR_ANY;	

	ser.sin_family = AF_INET;
	ser.sin_port = htons(5500);
	inet_pton(AF_INET, "172.20.22.121", &ser.sin_addr);	

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
	while(1){	
		printf("type the message\n");
		scanf("%s", buff);
		if(send(sock, (void*) buff, sizeof(buff), 0) < 0){
		perror("sen:");
		}
		if(strcmp(buff,"bye") == 0){
			break;
		}
		bzero(buff, sizeof(buff));
	
	}
	close(sock);
	return 0;
}
	
