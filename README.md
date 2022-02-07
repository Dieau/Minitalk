# Minitalk

This project's aim is to realize un small data exchange program using UNIX signals only.

# PROJECT INSTRUCTIONS

Executable files must be named client and server.

• You must render a Makefile which will compile your source files. He must not
relink.

• You must handle errors with common sense. Under no circumstances should your program quit unexpectedly (segmentation fault, bus error, double free, etc.).

• Your program must not have memory leaks.

• You can use one global variable per program (one for the client and one for the server) but their use must be justified.

• In order to do the mandatory part, you are allowed to use the following functions:

◦ write

◦ ft_printf and any equivalent YOU have coded
◦ signal

◦ sigemptyset

◦ sigaddset

◦ signature

◦ kill

◦ getpid

◦ malloc

◦ free

◦ break

◦ sleep

◦ usleep

◦ exit

# MANDATORY PART

You need to make a communication program in the form of a client and a server.

• The server must be launched first and must, after the launch, display its PID.

• The client takes two parameters:
The server PID.
/ A character string to transmit.

• The client must communicate to the server the string passed as a parameter. Once the string has been fully received, the server should display it.

• The server must be able to display the string quickly. By quickly, we mean that if you think it's too long, then it's probably too long.

Your server should be able to receive strings from multiple clients in a row without needing to be restarted.

• Communication between your programs should be done using UNIX signals only.

• You can only use the following two signals: SIGUSR1 and SIGUSR2.

# RESULT : 106 / 100.
