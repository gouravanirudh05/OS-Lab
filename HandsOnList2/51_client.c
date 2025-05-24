/*
Program Number: 51_client
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
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[1024] = {0};
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        printf("Client: ");
        fgets(buffer, 1024, stdin);

        send(client_socket, buffer, strlen(buffer), 0);

        read(client_socket, buffer, 1024);
        printf("Server: %s\n", buffer);
    }

    return 0;
}
