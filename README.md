# CCC
#### Video Demo:  <URL HERE>
#### Description:
The CMD Communication Code (CCC) project is a command-line chat application designed to facilitate real-time communication between a server and multiple clients over a network. It is implemented in C using the Winsock2 library, which enables reliable TCP communication. The project allows users to send and receive messages in a text-based chat environment, simulating a lightweight messaging system.

#### Features:
##### 1-Server-Client Communication:
A server program (server.c) that listens for incoming connections from clients.
Client programs (client.c or user82.c) that connect to the server and exchange messages.

##### 2-Real-Time Messaging:
Bi-directional messaging between the server and clients with minimal delay.
A clean user interface that maintains a conversation log.

##### 3-Multithreaded Architecture:
Both the server and clients use threads to handle sending and receiving messages concurrently, ensuring a smooth chat experience.

##### 4-Cross-Platform Support:
Designed for Windows, utilizing the Winsock2 library for network communication.
Can be extended to work on other platforms with minor modifications.

##### 5-Custom Command Automation:
Includes a Python script to automate file deletion and recompilation of server.c and client.c.



