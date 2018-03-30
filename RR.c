#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 1024
#define MAX 1024

typedef struct Process
{
    int pid,
        arrivalTime,
        burstTime,
        remainingTime,
        startTime,
        endTime,
        tickets;
};

struct Process intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

struct Process peek()
{
    return intArray[front];
}

bool isEmpty()
{
    return itemCount == 0;
}

bool isFull()
{
    return itemCount == MAX;
}

int size()
{
    return itemCount;
}

void enqueue(struct Process data)
{

    if (!isFull())
    {

        if (rear == MAX - 1)
        {
            rear = -1;
        }

        intArray[++rear] = data;
        itemCount++;
    }
}

struct Process dequeue()
{
    struct Process data = intArray[front++];

    if (front == MAX)
    {
        front = 0;
    }

    itemCount--;
    return data;
}

int main()
{

    char buffer[BUFFER_SIZE];
    char *record, *line;
    int i = 0, j = 0;
    FILE *fstream = fopen("Input1.in", "r");
    if (fstream == NULL)
    {
        printf("\n file opening failed ");
        return -1;
    }
    int quantum = atoi(fgets(buffer, sizeof(buffer), fstream));
    int totalTickets = atoi(fgets(buffer, sizeof(buffer), fstream));
    printf("%d\n%d\n",quantum,totalTickets);
    while ((line = fgets(buffer, sizeof(buffer), fstream)) != NULL)
    {
        record = strtok(line, ",");
        int i;
        int pid;
        int arrivalTime;
        int burstTime;
        int tickets;
        for (i = 0; record != NULL; ++i)
        {
            if (i == 0)
                pid = atoi(record);
            if (i == 1)
                arrivalTime = atoi(record);
            if (i == 2)
                burstTime = atoi(record);
            if (i == 3)
                tickets = atoi(record);

            record = strtok(NULL, ",");
        }
        struct Process p;
        p.arrivalTime=arrivalTime;p.pid=pid;p.burstTime=burstTime;p.remainingTime;p.burstTime;p.tickets=tickets;
        printf("%d %d %d  \n", p.pid, p.arrivalTime, p.burstTime);
        enqueue(p);



    }
    int time = -1000;
    double average_turnaround = 0;
    int nop = size(); //number of processes
    int ii = 0 ;
    struct Process p;
    while (size() != 0 && ii<20)
    {
         p = dequeue();

        if (p.remainingTime = p.burstTime)
            p.startTime = time;
     printf("llll %d\n",p.remainingTime);

        if (p.remainingTime == 0)
        {
            //sleep for sometime
            p.endTime = time;
            int turnaround = p.endTime - p.arrivalTime;
            average_turnaround += (turnaround / nop);
            printf("Time %d : P %d Done Turn around : %d Waiting time : %d\n", time, p.pid, turnaround, p.startTime - p.arrivalTime);
        }
        else
        {
            if (p.remainingTime <= quantum)
            {
                time += p.remainingTime;
                p.remainingTime = 0;
                dequeue();

            }
            else
            {
                time += quantum;
                p.remainingTime = p.remainingTime-quantum;
                printf("hhh %d\n",p.remainingTime);
                dequeue();
                enqueue(p);


            }
            printf("Time %d : P %d Entering quantum\n", time, p.pid);
        }
        ii++;
    }
    return 0;
}
