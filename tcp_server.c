#include <stdio.h>
#include <stdlib.h>
#include <sys/sockets.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(void){
	char server_response[256] = "Hey ther!! it works !!!";

	int server_socket;
	server_socket = socket(AF_INET, SOCK_STEAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 10);
	int client_socket = accept(server_socket, NULL, NULL);

	send(client_socket, server_response, sizeof(server_response), 0);

	close(server_socket);

	return 0;


			
