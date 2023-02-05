# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Karla Vasquez
- Gila Kohanbash

## Lab Question Answers

*Question 1: How did the reliability of UDP change when you added 50% loss to your local
environment? Why did this occur?

  The reliability of the UDP decreased when the loss was added - everything really
  slowed down and not all messages were received.
  This probably happened because when the loss was added, the chances of every
  packet getting sent and received lessened.

*Question 2: How did the reliability of TCP change? Why did this occur?
  
  The reliability of TCP did not change so much since all everything sent was received on
  both sides - unlike UDP. This occurred since TCP has reliable and in-order delivery.
  
*Question 3: How did the speed of the TCP response change? Why might this happen?
  
  The speed of the TCP slowed down a lot when the loss was added - I realized I needed
  to wait a bit before seeing the messages I sent from the server to the client. This
  probably happened because with TCP, no packets will really ever get lost, so when the
  loss was added, the server had to detect lost packets and transmit them.
  
## TCP_server.c Questions:
*1. What is argc and *argv[]?*
  argc is the number of arguments given in the command line - the first argument will
  always be the code name.

  *argv[] is an array that holds all of the commands (in strings) so you can access any
  given input i by argv[i].

*2. What is a UNIX file descriptor and file descriptor table?*

  A file descriptor is usually an integer value given to a file or any other type of I/O source;
  they are used to identify an open file. File descriptors are an index into a file-descriptor
  table - the table is a collection of integer array indices that are file descriptors.
  
*3. What is a struct? What's the structure of sockaddr_in?*
  
  A struct is a way to group related variables and methods together in one place. The
  sockaddr_in structure has 4 variables: short sin_family, unsigned short sin_port, struct
  in_addr sin_addr, char sin_zero.
  These types of structs are usually used when you want to store the address of the
  server.
  
*4. What are the input parameters and return value of socket()?*

  The parameters are AF_INET which is the address domain of the socket,
  SOCK_STREAM is the type of socket - in this case it reads characters in a continuous
  stream, and the last parameter is the protocol - here we set it to 0 meaning the
  operating system will choose the most appropriate protocol. The return value is an entry
  into the file descriptor table.
  
*5. What are the input parameters of bind() and listen()?*

  For bind() the parameters are a socket file descriptor(sockfd), the address to which is
  bound(*serv_addr) and the size of the address. For listen() the parameters are a socket
  file descriptor (sockfd) and the number of connections that can be waiting (in this case
  5).
  
*6. Why use while(1)? Based on the code below, what problems might occur if there
are multiple simultaneous connections to handle?*

  The while loop makes sure that the server will handle one connection at a time in the
  order that the simultaneous connections come through. The loop allows the server to
  continuously run.
  
*7. Research how the command fork() works. How can it be applied here to better
handle multiple connections?*

  The fork() system call creates a new process that runs alone with the process that made
  the fork() called. It can be used here by creating a new process for each connection so
  when multiple connections come through, the server can handle many connections at
  the same time instead of one at a time.
  
*This program makes several system calls such as 'bind', and 'listen.' What exactly is a
system call?*

  A system call is the way a computer program requests or calls on a serve from the
  kernel it is being operated on. Basically, a system call is a way for programs to interact
  with the kernel.
