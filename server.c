#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>  // Windows threading library

#pragma comment(lib, "ws2_32.lib")  // Link winsock library

#define PORT 8080
#define BUFFER_SIZE 1024

SOCKET new_socket;

DWORD WINAPI receive_messages(LPVOID arg) {
    char buffer[BUFFER_SIZE] = {0};
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int valread = recv(new_socket, buffer, BUFFER_SIZE, 0);
        if (valread > 0) {
            printf("\rClient: %s\n", buffer);  // Display the message from the client
            printf("You (Server): ");         // Restore the input prompt
            fflush(stdout);                   // Force the prompt to display immediately
        }
    }
    return 0;
}

DWORD WINAPI send_messages(LPVOID arg) {
    char buffer[BUFFER_SIZE] = {0};
    while (1) {
        printf("You (Server): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove the newline character
        send(new_socket, buffer, strlen(buffer), 0);
    }
    return 0;
}

int main() {
    WSADATA wsa;
    SOCKET server_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code : %d\n", WSAGetLastError());
        return 1;
    }

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code : %d\n", WSAGetLastError());
        return 1;
    }

    // Configure address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code : %d\n", WSAGetLastError());
        return 1;
    }

    // Listen for connections
    listen(server_fd, 3);
    printf("Waiting for connections...\n");

    // Accept a connection
    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    if (new_socket == INVALID_SOCKET) {
        printf("Accept failed. Error Code : %d\n", WSAGetLastError());
        return 1;
    }
    printf("\nClient connected!\n");

    // Create threads for sending and receiving
    HANDLE send_thread = CreateThread(NULL, 0, send_messages, NULL, 0, NULL);
    HANDLE receive_thread = CreateThread(NULL, 0, receive_messages, NULL, 0, NULL);

    // Wait for threads to finish (they run indefinitely)
    WaitForSingleObject(send_thread, INFINITE);
    WaitForSingleObject(receive_thread, INFINITE);

    closesocket(server_fd);
    WSACleanup();
    return 0;
}
