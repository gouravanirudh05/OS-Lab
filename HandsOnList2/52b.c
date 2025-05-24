/*
Program Number: 52b
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program creates a concurrent TCP server using pthreads.
             The server listens on port 8080, and for each new client, it
             creates a new thread using pthread_create() to handle client communication.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8080
#define MAXLINE 1024

void *handle_client(void *arg)
{
    int new_socket = *(int *)arg;
    free(arg);

    char buffer[MAXLINE];
    read(new_socket, buffer, MAXLINE);
    printf("Client says: %s\n", buffer);
    write(new_socket, "Hello from server (thread)\n", 28);
    close(new_socket);
    return NULL;
}

int main()
{
    int server_fd, *new_socket;
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
    printf("Server using pthreads is running on port %d...\n", PORT);

    while (1)
    {
        new_socket = malloc(sizeof(int));
        *new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
        if (*new_socket < 0)
        {
            perror("Accept failed");
            free(new_socket);
            continue;
        }

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, new_socket);
        pthread_detach(tid); // Automatically free resources when done
    }

    return 0;
}
