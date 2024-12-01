#  CMD Communications Code (CCC) 
#### Explainer video: [<https://www.youtube.com/watch?v=efhDcUB6uKg>]

---

#### **Description**:
The CMD Communications Code (CCC) project is a command-line chat application designed to facilitate real-time communication between a server and multiple clients over a network. It is implemented in **C** using the **Winsock2** library, which enables reliable TCP communication. The project allows users to send and receive messages in a text-based chat environment that simulates a lightweight messaging system.

---

#### **Features**:
##### **1. Communication between server and client**:
- A server program ('server.c') that listens for incoming connections from clients.
- Client programs (`client.c') that communicate with the server and exchange messages.

##### **2. Real-time messaging**:
- Two-way messaging between server and clients with minimal delay.
- A clean user interface that keeps a conversation log.

##### **3. Multi-threaded architecture**:
- Both server and clients use threads to handle sending and receiving messages simultaneously, ensuring a seamless conversation experience.

##### **4. Cross-platform support**:
- Designed for Windows, using the Winsock2 library for network connectivity.
- Can be extended to work on other platforms with minor modifications.

##### **5. Custom command automation**:
- Includes a Python script to automate deleting files and recompiling 'server.c' and 'client.c'.

---

#### **How it works**:
1. **Server** listens for incoming client connections on a specific port (default: '8080').
2. When a client connects, the server creates a customized thread to handle the connection to that client.
3. The server broadcasts messages from one client to all connected clients.
4. Clients interact with the server using a text-based interface, where messages are displayed in real time.

---

#### **Code Components**:
- **Server code (`server.c`)**: Set up the TCP server, handle client connections, and manage message broadcasts.
- **Client code ('client.c')**: Connects to the server and allows users to send and receive messages.
- **Python automation script (`automate.py`)**: Deletes old binary files, compiles 'server.c' and 'client.c' for quick iteration.

---

#### **Install and use**:

##### **Basic Requirements**:
1. **C compiler**:
   - Install GCC (MinGW) to compile the code.
2. **Python**:
   - Make sure Python is installed to run the automation script.
3. **Windows operating system**:
   - Required for Winsock2 compatibility.

##### **Steps to run**:
1. Clone the repository:
   ```bash
   git clone https://github.com/Mr-PeterMaged/ccc
   cd ccc

2. Run the Python automation script to clean up old binaries and compile the code:
   ```bash
   python automate.py
   
3. Start the server in a terminal:
   ```bash
   ./server.exe
   
4. Start multiple clients in separate terminals:
   ```bash
   ./client.exe

---

##### **Example Workflow:**:
1. Server:
   ```bash
   Waiting for connections...
   Client connected!
   Client: Hello, Server.

2. Client1:
   ```bash
   Connected to server!
   You (Client): Hello, Server.
   Server: Hello, Client!
