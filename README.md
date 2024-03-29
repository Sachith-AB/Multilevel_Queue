# Multilevel_Queue
A multilevel queue is a scheduling algorithm that organizes processes into multiple priority levels, each with its own queue and scheduling policy.<br>
Each queue must be assigned a priority, with q0 having the highest priority and q3 having the lowest priority.<br>
The following scheduling algorithms should be used for each queue:<br>
● q0 - Round Robin (RR)<br>
● q1 - Shortest Job First (SJF)<br>
● q2 - Shortest Job First (SJF)<br>
● q3 - First-In-First-Out (FIFO)<br>
Each queue should be given a time quantum of 20 seconds, and the CPU should switch between queues after every 20 seconds.The user should be prompted to enter the number of processes along with their priority associated with each queue.<br>
