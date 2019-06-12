# OperatingSystem
CPU scheduling: your program should implement the round-robin scheduling. 
We do not implement any real time counting. 
We only use a special text command Q A etc to indicate that the currently running process exceeded its time quantum.
Memory: your program should simulate the demand paging memory management. 
When a new process appears in the system, it is not loaded into memory.
Later pages are added only when needed (when corresponding m command is used). 
If a page needs to be loaded into the memory but there is no place for it, swap from the RAM the least recently used page
(it can belong to any process).
At the start, your program asks the user three questions:
How much RAM memory is there on the simulated computer?
Your program receives the number in bytes (no kilobytes or words).
I can enter any number up to 4gb
What is the size of a page/frame. The enumeration of pages starts from 0.
How many hard disks does the simulated computer have?
The enumeration of the hard disks starts with 0.
Then the program creates an initial process with pid 1. 
This is a system process and it cannot be terminated. 
All other processes in your simulated system are the descendants of this one. 
In our simulation only, this process never uses the CPU or memory (which is COMPLETELY UNREALISTIC as you can understand).
After that, the simulation begins. 
