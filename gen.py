import os
import subprocess

# Define the commands to execute
commands = [
    "del server.exe",                     # Delete server.exe
    "del client.exe",                     # Delete client.exe
    "gcc server.c -o server.exe -lws2_32",  # Compile server.c
    "gcc client.c -o client.exe -lws2_32" ,  # Compile client.c
    

]

# Execute the commands
for cmd in commands:
    try:
        print(f"Running: {cmd}")
        # Use subprocess to execute the command
        result = subprocess.run(cmd, shell=True, check=True, text=True, capture_output=True)
        print(result.stdout)  # Print the standard output
    except subprocess.CalledProcessError as e:
        print(f"Error occurred while running: {cmd}")
        print(e.stderr)  # Print the error output
