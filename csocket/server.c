#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#define MAX_BUFFER_SIZE 100 

void handle_echo_mode(int client_socket); 
void handle_file_transfer_mode(int client_socket); 

int main(int argc, char *argv[]) 
{     

if (argc != 2) 
{         
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);         
    exit(1);     
}     

int port = atoi(argv[1]);     
int sockfd = socket(AF_INET, SOCK_STREAM, 0);   

if (sockfd < 0) 
{         
    perror("Error opening socket");         
    exit(1);     
}     

struct sockaddr_in serv_addr;     
memset(&serv_addr, 0, sizeof(serv_addr));     
serv_addr.sin_family = AF_INET;     
serv_addr.sin_addr.s_addr = INADDR_ANY;     
serv_addr.sin_port = htons(port);    

if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
{         
    perror("Error binding socket");         
    exit(1);     
} 

listen(sockfd, 5);     
printf("Server listening on port %d...\n", port);    

while (1) 
{         
    struct sockaddr_in client_addr;         
    socklen_t client_addr_len = sizeof(client_addr);         
    int client_socket = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);         
    if (client_socket < 0) 
    {             
        perror("Error accepting connection");             
        exit(1);         
    }         
    printf("Accepted a connection from a client.\n");          
    char mode[MAX_BUFFER_SIZE];         
    ssize_t recv_mode = recv(client_socket, mode, sizeof(mode) - 1, 0);         
    if (recv_mode == -1) 
    {             
            perror("Error receiving mode");             
            exit(1);         
    }  

    mode[recv_mode] = '\0';    

    if (strcmp(mode, "1") == 0) 
    {             
        handle_echo_mode(client_socket);         
    }
    else if (strcmp(mode, "2") == 0) 
    {             
        handle_file_transfer_mode(client_socket);         
    }         
    close(client_socket);         
    printf("Closed the connection.\n");     
}     
close(sockfd);     
return 0; 
} 


void handle_echo_mode(int client_socket) 
{     
char buffer[MAX_BUFFER_SIZE];     
while (1) 
{         
    ssize_t recv_result = recv(client_socket, buffer, sizeof(buffer) - 1, 0);  

    if (recv_result == -1) 
    {             
        perror("Error receiving data");             
        exit(1);         
    }         

    buffer[recv_result] = '\0';   

    if (strcmp(buffer, "close") == 0) 
    {             
        printf("Received 'close' command. Sending 'goodbye'...\n");             
        send(client_socket, "goodbye", strlen("goodbye"), 0);             
        break;         
    }         
    
    printf("Received: %s\n", buffer);         
    send(client_socket, buffer, strlen(buffer), 0);     
} 
}

void handle_file_transfer_mode(int client_socket) 
{     
FILE *file = fopen("file.txt", "rb");   

if (file == NULL) 
{         
    perror("Error opening file");         
    exit(1);     
}     

char buffer[MAX_BUFFER_SIZE];     
size_t bytes_read;  

while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file)) > 0) 
{ 
    if (send(client_socket, buffer, bytes_read, 0) == -1) 
        { 
            perror("Error sending file"); exit(1);
        } 
}

fclose(file);
printf("File transfer completed.\n");
}
