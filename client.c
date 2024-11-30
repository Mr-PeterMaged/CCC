#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>  // Windows threading library

#pragma comment(lib, "ws2_32.lib")  // Link winsock library

#define PORT 8080
#define BUFFER_SIZE 1024

SOCKET sock;

DWORD WINAPI receive_messages(LPVOID arg) {
    char buffer[BUFFER_SIZE] = {0};
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int valread = recv(sock, buffer, BUFFER_SIZE, 0);
        if (valread > 0) {
            printf("\rServer: %s\n", buffer);  // Display the message from the server
            printf("You (Client): ");         // Restore the input prompt
            fflush(stdout);                   // Force the prompt to display immediately
        }
    }
    return 0;
}

DWORD WINAPI send_messages(LPVOID arg) {
    char buffer[BUFFER_SIZE] = {0};
    while (1) {
        printf("You (Client): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove the newline character
        send(sock, buffer, strlen(buffer), 0);
    }
    return 0;
}

int main() {
    WSADATA wsa;
    struct sockaddr_in server;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code : %d\n", WSAGetLastError());
        return 1;
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code : %d\n", WSAGetLastError());
        return 1;
    }

    // Configure server
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed. Error Code : %d\n", WSAGetLastError());
        return 1;
    }
    printf("Connected to server!\n");

    // Create threads for sending and receiving
    HANDLE send_thread = CreateThread(NULL, 0, send_messages, NULL, 0, NULL);
    HANDLE receive_thread = CreateThread(NULL, 0, receive_messages, NULL, 0, NULL);

    // Wait for threads to finish (they run indefinitely)
    WaitForSingleObject(send_thread, INFINITE);
    WaitForSingleObject(receive_thread, INFINITE);

    closesocket(sock);
    WSACleanup();
    return 0;
}
