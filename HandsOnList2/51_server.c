/*
Program Number: 51_server
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to communicate
between two machines using sockets.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int main()
{
    int server_fd, client_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        valread = read(client_socket, buffer, 1024);
        printf("Client: %s\n", buffer);
        printf("Server: ");
        fgets(buffer, 1024, stdin);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    return 0;
}
