#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define MYPORT ("3490")
#define BLACKLOG (10)

//int send(int sockfd, const void*msg, int len, int flags);
//int recv(int sockfd, void *buff, int len, int flags);

//struct socket

int main(void)
{
	struct sockaddr_storage their_addr;
	socklen_t addr_size;
	struct addrinfo hints,*res;
	int sockfd, new_fd;
	memset(&hints,0,sizeof(hints));
	hints.ai_family = AF_UNSPEC; //puede ser tipo ipv4 o ipv6
	hints.ai_socktype = SOCK_STREAM; //o DGRAM
	//hints.ai_flags = AI_PASSIVE;
	getaddrinfo(NULL,MYPORT,&hints,&res);
	sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	bind(sockfd,res->ai_addr,res->ai_addrlen);
	listen(sockfd,BLACKLOG);
	addr_size = sizeof(their_addr);
	printf("\n\t%d\n",addr_size);
	new_fd = accept(sockfd,(struct sockaddr*)&their_addr,&addr_size);	
}
