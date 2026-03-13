#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void generateOTP()
{
    if(rear == MAX - 1)
    {
        printf("Queue is full! Cannot generate more OTPs.\n");
        return;
    }

    srand(time(0));
    int otp = rand() % 900000 + 100000;

    if(front == -1)
        front = 0;

    rear++;
    queue[rear] = otp;

    printf("OTP Generated: %d\n", otp);
}

void verifyOTP()
{
    int userotp;

    if(front == -1)
    {
        printf("No OTP available. Generate OTP first.\n");
        return;
    }

    printf("Enter OTP: ");
    scanf("%d", &userotp);

    if(userotp == queue[front])
    {
        printf("OTP Verified Successfully!\n");
        front++;

        if(front > rear)
        {
            front = rear = -1;
        }
    }
    else
    {
        printf("Invalid OTP!\n");
    }
}

void displayQueue()
{
    if(front == -1)
    {
        printf("No OTP in queue.\n");
        return;
    }

    printf("Current OTPs in Queue:\n");

    for(int i = front; i <= rear; i++)
    {
        printf("%d\n", queue[i]);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== OTP SYSTEM USING QUEUE =====\n");
        printf("1. Generate OTP\n");
        printf("2. Verify OTP\n");
        printf("3. Display OTP Queue\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                generateOTP();
                break;

            case 2:
                verifyOTP();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}