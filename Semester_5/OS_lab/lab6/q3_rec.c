/*Write two programs named Interface and Display for the following problem.
Interface program
This program, when run, gives a prompt to the user as “Enter your message:”When the
user enters his/her message string and presses Enter, the program writes the message
into the shared memory, tells the Display to start processing,and then prompts the user
again for another message.
Display program
The process waits until a new message becomes available on the sharedmemory. Then it
reads the contents of the memory and prints it on the screen. It also clears the contents
of the shared memory when it has read the message.*/

//