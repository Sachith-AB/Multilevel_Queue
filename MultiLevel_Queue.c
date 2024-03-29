#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for process
typedef struct {
    char name[100];
    int burst_time;
    int remaining_time;
} process;

// Function to enqueue a process
void enqueue(process *q, int *size, process p) {
    q[*size] = p;
    (*size)++;
}

// Function to dequeue a process
process dequeue(process *q, int *size) {
    process temp = q[0];
    int i;
    (*size)--;
    for (i = 0; i < *size; i++) {
        q[i] = q[i + 1];
    }
    return temp;
}

// Function for Round Robin scheduling
void Round_Robin(process *Q, int *size, int T, int quantem) {
    while (*size > 0 && T > 0) {
        process temp = dequeue(Q, size);
        if (temp.remaining_time >= quantem) {
            printf("%s is executing for %d seconds\n", temp.name, quantem);
            T -= quantem;
            temp.remaining_time -= quantem;
            if (temp.remaining_time == 0) {
                printf("%s is executed\n", temp.name);
            } else {
                enqueue(Q, size, temp);
            }
        } else if (temp.remaining_time > 0) {
            printf("%s is executed\n", temp.name);
            T -= temp.remaining_time;
            temp.remaining_time = 0;
        } else {
            T = 0;
        }

        if (T <= 0) {
            break;
        }
    }
}

// Function for Shortest Job First scheduling
void SJF(process *Q, int *size, int T) {
	
	
    while(T>0&& *size>0){
		int i=0,shortest_jobid=0;
		for(i=0;i<*size;i++){
			if(Q[i].remaining_time<Q[shortest_jobid].remaining_time){
				shortest_jobid=i;
			}
		}
		process temp=dequeue(Q+shortest_jobid,size);
		if(temp.remaining_time>=T){
			temp.remaining_time=temp.remaining_time-T;
			
			T=0;
			if(temp.remaining_time==0){
				printf("%s is executed\n", temp.name);
				
			}
			else{
				enqueue(Q,size,temp);
			}
			
		}
		else{
			T=T-temp.remaining_time;
			
			temp.remaining_time=0;
			printf("%s is executed\n", temp.name);
			
		}
	
		
	}
	
	
	
	
	
	
}


// Function for First In First Out scheduling
void FIFO(process Q[], int *size, int T) {
    while (T > 0 && *size > 0) {
        process temp = dequeue(Q, size);
        if (temp.burst_time >= T || T <= 0) {
            printf("%s is executed\n", temp.name);
            T = 0;
        } else {
            printf("%s is executed\n", temp.name);
            T -= temp.burst_time;
        }
    }
}

int main() {
    const int T = 20;
    int nop, p, quantam;

    printf("How many processes do you want to execute: ");
    scanf("%d", &nop);

    process Q0[nop];
    process Q1[nop];
    process Q2[nop];
    process Q3[nop];

    int q0 = 0, q1 = 0, q2 = 0, q3 = 0;
	int i;
    for ( i = 0; i < nop; i++) {
        process newprocess;
        printf("Enter name of process %d: ", i + 1);
        scanf("%s", newprocess.name);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &newprocess.burst_time);
        printf("Enter priority for process %d (1 to 4): ", i + 1);
        scanf("%d", &p);
        newprocess.remaining_time = newprocess.burst_time;
        if (p == 1) {
            enqueue(Q0, &q0, newprocess);
        } else if (p == 2) {
            enqueue(Q1, &q1, newprocess);
        } else if (p == 3) {
            enqueue(Q2, &q2, newprocess);
        } else if (p == 4) {
            enqueue(Q3, &q3, newprocess);
        } else {
            printf("Invalid priority. Please enter a priority between 1 and 4.\n");
            return 0;
        }
    }

    printf("Enter round robin quantum: ");
    scanf("%d", &quantam);

    while (q0 > 0 || q1 > 0 || q2 > 0 || q3 > 0) {
        if (q0 != 0) {
            printf("Executing Queue 0 (Round Robin)...\n");
            Round_Robin(Q0, &q0, T, quantam);
        }

        if (q1 != 0) {
            printf("Executing Queue 1 (SJF)...\n");
            SJF(Q1, &q1, T);
        }

        if (q2 != 0) {
            printf("Executing Queue 2 (SJF)...\n");
            SJF(Q2, &q2, T);
        }

        if (q3 != 0) {
            printf("Executing Queue 3 (FIFO)...\n");
            FIFO(Q3, &q3, T);
        }
    }
    return 0;
}

