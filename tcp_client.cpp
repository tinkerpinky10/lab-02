// Server side C/C++ program to demonstrate Socket programming 
// Here's some include statements that might be helpful for you
#include <string> 
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[]) 
{ 
	// check to see if user input is valid
	char socket_read_buffer[1024];

	// TODO: Fill out the server ip and port

	std::string server_ip = "kdvasque";
	std::string server_port = "8000";

	int opt = 1;
	int client_fd = -1;

	// TODO: Create a TCP socket()
	client_fd = socket(AF_INET, SOCK_STREAM,0);

	// Enable reusing address and port
	if (setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
		return -1;
	}
	

	// Check if the client socket was set up properly
	if(client_fd == -1){
		printf("Error- Socket setup failed");
		return -1;
	}
	
	// Helping you out by pepping the struct for connecting to the server
	struct addrinfo hints;
	struct addrinfo *server_addr;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	getaddrinfo(server_ip.c_str(), server_port.c_str(), &hints, &server_addr);

	
	// TODO: Connect() to the server (hint: you'll need to use server_addr)



	connect(client_fd,server_addr->ai_addr,server_addr->ai_addrlen);
	// TODO: Retreive user input
	std::string theInput = "";
	std::cout << "Please enter a message: ";
	std::getline(std::cin, theInput);

	// TODO: Send() the user input to the server
	send(client_fd, theInput.c_str(), theInput.length(), 0);

	printf("Sent");
	// TODO: Recieve any messages from the server and print it here. Don't forget to make sure the string is null terminated!;
	recv(client_fd, socket_read_buffer, 1024, 0);
	printf("%s\n",socket_read_buffer);
	// TODO: Close() the socket
	close(client_fd);
	return 0; 
} 
