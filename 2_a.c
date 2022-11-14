#include<stdio.h>

#include<unistd.h>

#include<sys/types.h>

#define MAX 20

void quicksort(int a[], int, int);

void merge(int a[], int low, int mid, int high);

void divide(int a[], int low, int high);

void zombie(pid_t pid, int a[], int n, int i) {

  printf("\n\tEnter the no. of elements: ");

  scanf("%d", & n);

  printf("\n\tEnter the elements: \n");

  for (i = 0; i < n; i++) {
    printf("\t");
    scanf("%d", & a[i]);
  }
  pid = fork();

  if (pid < 0) {
    printf("Error While creating a new process.....!!!!!!");
  } else if (pid == 0) {
    printf("\n\t==============Child process started=============");
    printf("\n\tI am a child process with pid=%d and ppid=%d", getpid(), getppid());
    quicksort(a, 0, n - 1);
    printf("\n\n\tSorted array by quick sort:\n\t");
    for (i = 0; i < n; i++)
      printf("%d\t", a[i]);
    printf("\n");

    printf("\n\t==============Child process terminated=============\n");
  } else {
    wait();
    printf("\n\t==============Parent process started=============");
    printf("\n\n\tI am a parent process with pid=%d ", getpid());
    divide(a, 0, n - 1);
    printf("\n\n\tSorted array by merge sort:\n\t");

    for (i = 0; i < n; i++)
      printf("%d\t", a[i]);
    printf("\n");
    printf("\n\t==============Parent process terminated=============\n");

  }

}

void orphan(pid_t pid, int a[], int n, int i) {
  printf("\n\tEnter the no. of elements: ");

  scanf("%d", & n);

  printf("\n\tEnter the elements: \n");

  for (i = 0; i < n; i++)

  {

    printf("\t");

    scanf("%d", & a[i]);

  }

  pid = fork();
  if (pid < 0)

  {
    printf("Error While creating a new process.....!!!!!!");

  } else if (pid == 0)

  {

    wait();

    printf("\n\t==============Child process started=============");

    printf("\n\tI am a child process with pid=%d and ppid=%d", getpid(), getppid());

    quicksort(a, 0, n - 1);

    printf("\n\n\tSorted array by quick sort:\n\t");

    for (i = 0; i < n; i++)

      printf("%d\t", a[i]);

    printf("\n");

    printf("\n\t==============Child process terminated=============\n");

  } else {

    printf("\n\t==============Parent process started=============");

    printf("\n\n\tI am a parent process with pid=%d ", getpid());

    divide(a, 0, n - 1);

    printf("\n\n\tSorted array by merge sort:\n\t");

    for (i = 0; i < n; i++)

      printf("%d\t", a[i]);

    printf("\n");

    printf("\n\t==============Parent process terminated=============\n");

  }

}

int main()

{

  pid_t pid;

  int a[MAX], n;

  int i, op;

  printf("\n\tEnter 1) for zombie and 2) for orphan ");
  scanf("%d", & op);

  if (op == 1) {
    zombie(pid, a, n, i);
  } else if (op == 2) {
    orphan(pid, a, n, i);
  }

  execl("/bin/ps", "ps", NULL);
  return 0;

}

void quicksort(int a[MAX], int first, int last)

{

  int pivot, j, i, temp;

  if (first < last)

  {

    i = first;

    j = last;

    pivot = first;

    while (i < j)

    {

      while (a[i] <= a[pivot] && i < last)

        i++;

      while (a[j] > a[pivot])

        j--;

      if (i < j)

      {

        temp = a[i];

        a[i] = a[j];

        a[j] = temp;

      }

    }

    temp = a[j];

    a[j] = a[pivot];

    a[pivot] = temp;

    quicksort(a, first, j - 1);

    quicksort(a, j + 1, last);

  }

}

void divide(int a[MAX], int low, int high)

{

  if (low < high)

  {

    int mid = (low + high) / 2;

    divide(a, low, mid);

    divide(a, mid + 1, high);

    merge(a, low, mid, high);

  }

}

void merge(int a[MAX], int low, int mid, int high)

{

  int i, j, k, m = mid - low + 1, n = high - mid;

  int first_half[m], second_half[n];

  for (i = 0; i < m; i++)

    first_half[i] = a[low + i];

  for (i = 0; i < n; i++)
    second_half[i] = a[mid + i + 1];

  i = j = 0;

  k = low;

  while (i < m || j < n)

  {

    if (i >= m)

    {

      a[k++] = second_half[j++];

      continue;

    }

    if (j >= n)

    {

      a[k++] = first_half[i++];

      continue;

    }

    if (first_half[i] < second_half[j])

      a[k++] = first_half[i++];

    else

      a[k++] = second_half[j++];

  }

}
