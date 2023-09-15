#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void){
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	if (connection_status == -1){
		printf("There was an error in connecting the c=socket to the specified server");
	}

	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);

	printf("The server responded with %s\n\n", server_response);
	
	return 0;
}

