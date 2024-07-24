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

	/* ******************************************************************
	 * 소켓 생성
	 * int socket(int domain, int type, int protocol)
	 * 1. domain - 소켓이 사용할 프로토콜
	 *    AF_INET : IPv4
	 *    AF_INET6 : IPv6
	 *
	 * 2. type - 소켓의 타입
	 *    SOCK_STREAM : TCP
	 *    SOCK_DGRAM : UDP
	 * 
	 * 3. protocol - 소켓이 사용할 특정 프로토콜
	 *    IPPROTO_TCP
	 *    IPPROTO_UDP
	 *    0으로 설정하면 자동
	 *
	 * 소켓 생성 실패 시 -1 반환 
	 * 생성한 소켓 변수
	 * int s_socket
	 * ******************************************************************
	 */
		
	// -- 서버 소켓 생성 코딩--
	// 여기에 코등 하세요
	
	// -- 서버 소켓 생성 코딩 --

		
	/* ******************************************************************
	 * 바인드(bind) - IP 주소와 PORT 번호를 소켓에 연결
	 *              - IP 주소와 PORT 번호는 구조체 변수에 담아서 표현
	 *              - 구조체 sockaddr_in
	 *
	 * IPv4 기반의 주소표현을 위한 구조체
	 *
	 * struct sockaddr_in
	 * {
	 * 	sa_family_t	sin_family;  // 주소 체계
	 * 	uint16_t	sin_port;    // PORT 번호
	 * 	struct in_addr	sin_addr;    // 32비트 IP주소
	 * 	char		sin_zero[8]; // 사용되지 않음
	 * };
	 *
	 *
	 * struct in_addr
	 * {
	 * 	in_addr_t	s_addr;
	 * };
	 *
	 *
	 * 바인드
	 * int bind(int sockfd, struct sockaddr *addr, socklen_t addrlen);
	 * 1. sockfd - 바인딩할 소켓의 파일디스크립터, 생성한 소켓(s_socket)
	 * 2. sockaddr *addr - 소켓을 바인딩할 주소 정보를 가진 구조체 포인터
	 *    struct sockaddr
	 *    {
	 *    	sa_family_t 	sin_family;
	 *    	char		sa_data[14];
	 *    };
	 *    
	 *    - sockaddr_in 구조체를 sockaddr 구조체로 형변환해야함.
	 *    - sockaddr_in 구조체를 바로 사용하지 않는 이유는 
	 *    - IPv6와 같은 다양한 주소 체계를 저장하기 위함.
	 *    - sockaddr_in char sin_zero[8] 변수가 사용되지 않는 이유
	 * 3. addrlen - addr인자가 가리키는 구조체의 크기
	 * 
	 * 서버 구조체 변수		- struct sockaddr_in serv_adr;
	 * 클라이언트 구조체변수	- struct sockaddr_in clnt_adr;
	 *
	 * 구조체 초기화 
	 * memset(&serv_adr, 0, sizeof(serv_adr);
	 *
	 * bind 성공 시 0, 실패 시 -1 반환
	 ********************************************************************
	 */

		
	// -- bind 코딩 --
	// 여기에 코딩하세요
	
	// -- bind 코딩 --

	/* **************************************************************************
	 * listen
	 *
	 * int listen(int sockfd, int backlog);
	 * 1. sockfd - 수신 대기 상태로 만들 소켓의 파일 디스크립터
	 * 2. backlog - 대기열의 최대 크기
	 *
	 * ***************************************************************************
	 */	

	// -- listen 코딩 --
	// 여기에 코딩 하세요
	
	// -- listen 코딩 --
	
	/******************************************************************************************
	 * accept
	 * int accept(int socket, struct sockaddr *address, socklent_t *address_len);
	 * 1. socket - 이 인수는 서버 소켓의 파일 디스크립트
	 *           - 이 소켓을 통해 클라이언트의 연결 요청을 받음
	 * 2. address - 이 인수는 클라이언트의 주소 정보를 받을 구조체
	 * 3. address_len - 구조체의 크기를 나타내는 포인터
	 * 		  - 크기 정보를 변수에 저장한 다음, 변수의 주소 값을 전달
	 * 		  - int addrlen = sizeof(clnt_adr) 
	 */

	// -- accept 코딩 --
	// 여기에 코딩하세요.
	
	// -- accept 코딩 --
	
	close(s_socket);
	
	return 0;
}


