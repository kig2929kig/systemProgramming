#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char** argv) {

	int c_socket;
	struct sockaddr_in s_addr;
	char *serv_port = argv[2];
	char *serv_ip = argv[1];
	char message[BUF_SIZE];
	int str_len;

	// socket
	c_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (c_socket == -1) {
		printf("socket failed \n");
		return 1;
	}
	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(atoi(serv_port));
	s_addr.sin_addr.s_addr = inet_addr(serv_ip);
	// socket
	
	// connect
	if (connect(c_socket, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1) {
		printf("connect failed \n");
		return 1;
	}
	printf("Connected to the server. \n");
	// connect
	
	while(1) {
		fputs("Input message(Q to quit) :", stdout);
		fgets(message, BUF_SIZE, stdin);

		if(!strcmp(message, "q\n") || !strcmp(message, "Q\n")) break;

		write(c_socket, message, strlen(message));
		str_len= read(c_socket, message, BUF_SIZE-1);
		message[str_len]=0;
		printf("Message from server : %s", message);	
	}
	close(c_socket);

	return 0;
}

