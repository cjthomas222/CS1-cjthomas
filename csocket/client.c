#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 100

void handle_echo_mode(int sockfd);
void handle_file_transfer_mode(int sockfd);

int main(int argc, char *argv[]) {
if (argc != 4) {
    fprintf(stderr, "Usage: %s <server_address> <port> <mode>\n", argv[0]);
    exit(1);
}

char *server_address = argv[1];
int port = atoi(argv[2]);
int mode = atoi(argv[3]);
int sockfd = socket(AF_INET, SOCK_STREAM, 0);

if (sockfd < 0) 
{
    perror("Error opening socket");
    exit(1);
}

struct hostent *server = gethostbyname(server_address);

if (server == NULL) {
    fprintf(stderr, "Error: No such host '%s'\n", server_address);
    exit(1);
}

struct sockaddr_in serv_addr;
memset(&serv_addr, 0, sizeof(serv_addr));

serv_addr.sin_family = AF_INET;
memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
serv_addr.sin_port = htons(port);

if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to the server");
    exit(1);
}

printf("Connected to the server.\n");

char mode_str[MAX_BUFFER_SIZE];
sprintf(mode_str, "%d", mode);

if (send(sockfd, mode_str, strlen(mode_str), 0) == -1) {
    perror("Error sending mode");
    exit(1);
}

if (mode == 1) {
    handle_echo_mode(sockfd);
} else if (mode == 2) {
    handle_file_transfer_mode(sockfd);
}

close(sockfd);
return 0;
}

void handle_echo_mode(int sockfd) 
{

char buffer[MAX_BUFFER_SIZE];

while (1) 
{
    printf("Enter a string to send (or 'close' to exit): ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';  

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) 
    {
        perror("Error sending data");
        exit(1);
    }

    if (strcmp(buffer, "close") == 0) 
    {
        break;
    }

    ssize_t recv_result = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (recv_result == -1) 
    {
        perror("Error receiving data");
        exit(1);
    }

    buffer[recv_result] = '\0'; 
    printf("Received: %s\n", buffer);
}
}

void handle_file_transfer_mode(int sockfd) 
{
FILE *file = fopen("received_file.txt", "wb");
if (file == NULL) {
    perror("Error opening file");
    exit(1);
}

char buffer[MAX_BUFFER_SIZE];
ssize_t bytes_received;

while((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) 
{
    if (fwrite(buffer, sizeof(char), bytes_received, file) != bytes_received) 
    {
        perror("Error writing to file");
        exit(1);
    }
}
fclose(file);
printf("File transfer completed.\n");
}