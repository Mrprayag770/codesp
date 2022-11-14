#include<stdio.h>

int max[10][10], allocation[10][10], need[10][10];
int avail[10];
int nop, nor;

void readmatrix(int matrix[10][10])
{
    int i, j;
    for(i = 0; i < nop; i++)
    for(j = 0; j < nor; j++)
       scanf("%d", &matrix[i][j]);
}

void display_matrix(int matrix[10][10])
{

    int i, j;
    for (i = 0; i < nop; i++)
    {
        printf("\n P%d", i);
        for (j = 0; j < nor; j++)
        {
            printf("  %d", matrix[i][j]);
        }
    }
}

void calculate_need()
{
    int i, j;
    for (i = 0; i < nop; i++)
    for (j = 0; j < nor; j++)
        need[i][j] = max[i][j] - allocation[i][j];
}

void banker()
{
    int i, j, k = 0, flag;
    int finish[10], safe_seq[10]; // f = 0 for incomplete && f = 1 for complete

    for (i = 0; i < nop; i++)
    {
        finish[i] = 0;
    }

    for (i = 0; i < nop; i++)
    {
        flag = 0;
        if (finish[i] == 0) // exe incomp process
        {
            for (j = 0; j < nor; j++)
            { // check need of each proc
                if (need[i][j] > avail[j])
                {
                    flag = 1; // break a loop as need is >g than avail
                    break;
                }
            }

            if (flag == 0) // need is less than available
            {
                finish[i] = 1;
                safe_seq[k] = i;
                k++;

                for (j = 0; j < nor; j++)
                    avail[j] += allocation[i][j];

                i = -1; // start checking from 1st proc again
            }
        }
    }

    flag = 0; // check if all proc are completed

    for (i = 0; i < nop; i++)
    {
        if (finish[i] == 0)
        {
            printf("\n the system is in deadlock");
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("\n sys is in safe state \n safe seq is ===>");
        for (i = 0; i < nop; i++)
            printf("  P%d", safe_seq[i]);
    }
}

int main()
{
    int j;
    // read input
    
        printf("\n enter no of processes");
        scanf("%d", &nop);

        printf("\n enter no of resources");
        scanf("%d", &nor);

        printf("\n enter inital allo: ");
        printf("\n");

        readmatrix(allocation);
        printf("\n");

        printf("\n enter max req: ");
        readmatrix(max);
        printf("\n");

        printf("\n enter avail resources: ");
        for (j = 0; j < nor; j++)
            scanf("%d", &avail[j]); // avail -- p1= 223, p2=333, p3=100
    

    // display matrix
    
        printf("\n ************Entered data is **********\n\n");
        printf("\n");

        printf("\n initia allocation:\n");
        display_matrix(allocation);

        printf("\n");
        printf("\n initia max reqs:\n");
        display_matrix(max);

        printf("\n");
        printf("\n available resources\n");
        for (j = 0; j < nor; j++)
            printf("%d", avail[j]);
    

    // cal need
    
        calculate_need();
        printf("\n\n\n ********** nees********** is \n"); // fter cal-ig need print it
        printf("\n");
        
        display_matrix(need);
    

    // exec process using bankers algorithm prayag

    
        banker();
        printf("\n\n\n\n");
        return 0;
    
}
