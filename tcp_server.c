#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
	char server_message[256] = "This is the server and this is the message";
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	bind(server_socket, (const struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 10);
	
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);

	send(client_socket, server_message, sizeof(server_message), 0);
	close(server_socket);
	return 0;
}
