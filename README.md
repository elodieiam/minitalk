# Minitalk Project 📡
The minitalk project at 42 School involves creating a simple messaging system between two programs using UNIX signals (SIGUSR1 and SIGUSR2). 📬

This project enhances our understanding of inter-process communication and signal handling in a Unix-based environment.

## Features 📋
1. **Message Transmission:** Send and receive messages between two programs.
2. **Signal Handling:** Use UNIX signals for communication.
3. **Error Management:** Ensure robust error handling for reliable messaging.

## Objectives 🎯
1. Master inter-process communication using signals.
2. Develop robust error handling strategies.
3. Improve understanding of Unix-based systems.

## Usage 📜
First, start the **server program**. It will display its PID (Process ID), which you need for the client.

Next, start the **client program** by providing the server's PID and the message to be sent.

Note: the server will keep running continuously as it will listen for incoming signals from the client.

## Output 🖼️
Here is a screenshot showing the output of the program with a basic message:
![Capture d’écran 2024-08-20 202156](https://github.com/user-attachments/assets/01af004b-1a9b-47ac-abf1-7e2afebb54b7)

## Installation 🛠️

To explore the minitalk project :
git clone git@github.com:elodieiam/minitalk.git
