/*
Program Number: 52a
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program creates a concurrent TCP server using fork().
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define MAXLINE 1024

void handle_client(int new_socket)
{
    char buffer[MAXLINE];
    read(new_socket, buffer, MAXLINE);
    printf("Client says: %s\n", buffer);
    write(new_socket, "Hello from server (fork)\n", 26);
    close(new_socket);
}

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    printf("Server using fork is running on port %d...\n", PORT);

    while (1)
    {
        new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
        if (new_socket < 0)
        {
            perror("Accept failed");
            continue;
        }

        pid_t pid = fork();
        if (pid == 0)
        { // Child process
            close(server_fd);
            handle_client(new_socket);
            exit(0);
        }
        else if (pid > 0)
        {
            close(new_socket); // Parent closes copy
        }
    }

    return 0;
}
