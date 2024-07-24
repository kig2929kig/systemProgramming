#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


#define BUF_SIZE 1024

int main() {
	int s_socket, c_socket;
	struct sockaddr_in serv_adr;
	struct sockaddr_in clnt_adr;
	char *serv_port = "8080";
	int addrlen = sizeof(clnt_adr);
	char message[BUF_SIZE];
	int str_len; 

		
	// -- 서버 소켓 생성 코딩--
	s_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s_socket == -1) {
		printf("[서버 소켓 생성 실패]\n");
		return 1;
	}else {
		printf("[서버 소켓 생성]\n");
		printf(" -> 파일 디스크립터 : %d\n", s_socket);
	}	
	// 서버 소켓 생성 코딩 --

		
	// -- bind 코딩 --
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_port = htons(atoi(serv_port));
	serv_adr.sin_addr.s_addr = INADDR_ANY;

	if(bind(s_socket, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1) {
		printf("[bind 실패]\n");
		return 1;
	}else {
		printf("[bind 성공]\n");
	}
	// -- bind 코딩 --


	// -- listen 코딩 --
	if (listen(s_socket, 5) == -1) {
		printf("[listen 실패]\n");
		return 1;
	}else {
		printf("[listen 성공]\n");
		printf(" -> port : %s\n", serv_port);
	}
	// -- listen 코딩 --
	

	// -- accept 코딩 --
	for (int i = 0; i<5; i++) {
		c_socket = accept(s_socket, (struct sockaddr *)&clnt_adr, (socklen_t *)&addrlen);
		if (c_socket == -1) {
			printf("[accept 실패]\n");
			return 1;
		}else {
			printf("[accept 성공]\n");
			printf(" -> 클라이언트 IP : %s \n", inet_ntoa(clnt_adr.sin_addr));
			printf(" -> 클라이언트 PORT : %d \n", ntohs(clnt_adr.sin_port));
		}

		while((str_len = read(c_socket, message, BUF_SIZE))!=0) {
			message[str_len] = 0;
			char tmp_msg[BUF_SIZE] = "echo=>";		
			printf("Message from client[%d] : %s",i, message);
			write(c_socket, strcat(tmp_msg,message) , strlen(strcat(tmp_msg, message)));
		}

		close(c_socket);

	}
	// -- accept 코딩 --
	
	close(s_socket);
	
	return 0;
}

