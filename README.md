# CMD Communication Code (CCC)
#### Video Demo: [<URL HERE>]
(*Replace `<URL HERE>` with the actual link to your video.*)

---

#### **Description**:
The CMD Communication Code (CCC) project is a command-line chat application designed to facilitate real-time communication between a server and multiple clients over a network. It is implemented in **C** using the **Winsock2 library**, which enables reliable TCP communication. The project allows users to send and receive messages in a text-based chat environment, simulating a lightweight messaging system.

---

#### **Features**:
##### **1. Server-Client Communication**:
- A server program (`server.c`) that listens for incoming connections from clients.
- Client programs (`client.c` or `user82.c`) that connect to the server and exchange messages.

##### **2. Real-Time Messaging**:
- Bi-directional messaging between the server and clients with minimal delay.
- A clean user interface that maintains a conversation log.

##### **3. Multithreaded Architecture**:
- Both the server and clients use threads to handle sending and receiving messages concurrently, ensuring a smooth chat experience.

##### **4. Cross-Platform Support**:
- Designed for Windows, utilizing the Winsock2 library for network communication.
- Can be extended to work on other platforms with minor modifications.

##### **5. Custom Command Automation**:
- Includes a Python script to automate file deletion and recompilation of `server.c` and `client.c`.

---

#### **How It Works**:
1. The **server** listens for incoming client connections on a specified port (default: `8080`).
2. When a client connects, the server spawns a dedicated thread to handle communication with that client.
3. The server broadcasts messages received from one client to all connected clients.
4. Clients interact with the server using a text-based interface, where messages are displayed in real-time.

---

#### **Code Components**:
- **Server Code (`server.c`)**: Sets up a TCP server, handles client connections, and manages message broadcasting.
- **Client Code (`client.c`, `user82.c`)**: Connects to the server, allows users to send and receive messages.
- **Python Automation Script (`automate.py`)**: Deletes old binary files, compiles `server.c` and `client.c` for quick iteration.

---

#### **Installation and Usage**:

##### **Prerequisites**:
1. **C Compiler**:
   - Install GCC (MinGW) for compiling the code.
2. **Python**:
   - Ensure Python is installed for running the automation script.
3. **Windows Operating System**:
   - Required for Winsock2 compatibility.

##### **Steps to Run**:
1. Clone the repository:
   ```bash
   git clone https://github.com/Mr-PeterMaged/ccc
   cd ccc
