#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
void bass(int arr[30], int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("\n Ascending Order \n");
	for (i = 0; i < n; i++)
		printf("\t%d", arr[i]);
	printf("\n\n\n");
}
void bdsc(int arr[30], int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("\n Descending Sorting \n\n");
	for (i = 0; i < n; i++)
		printf("\t%d", arr[i]);
	printf("\n\n\n");
}
void forkeg()
{
	int arr[25], n, i, status;
	printf("\nEnter the no of values in array: ");
	scanf("%d", &n);
	printf("\nEnter the array elements: ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int pid = fork();
	if (pid == 0)
	{
		sleep(4);
		printf("\n=================child process====================\n");
		printf("child process id=%d\n", getpid());
		bdsc(arr, n);
		for (i = 0; i < n; i++)
			printf("%d,", arr[i]);
		printf("\b");
		printf("\nparent process id=%d\n", getppid());
	}
	else
	{
		printf("\n================parent process====================\n");
		printf("\nparent process id=%d\n", getppid());
		printf("\nchild process id=%d\n", pid);

		bass(arr, n);
		for (i = 0; i < n; i++)
			printf("%d,", arr[i]);
		printf("\n\n\n");
	}
}
int main()
{
	forkeg();
	return 0;
}