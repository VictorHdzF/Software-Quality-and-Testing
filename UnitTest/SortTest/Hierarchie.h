#include <iostream>
#include <vector>

using namespace std;

class Sort
{
public:
    int n = 10;
    int arr[10] = {3,41,23,14,1,2,10,5,7,31};
    virtual void sort() = 0;

    void swap(int *x, int *y)
    {
      int temp = *x;
      *x = *y;
      *y = temp;
    }
};

class InsertionSort : public Sort
{
public:
    void sort()
    {
        int i, j, key;
        for (i = 1; i < n; i++)
        {
           key = arr[i];
           j = i - 1;
           while (j >= 0 && arr[j] > key)
           {
               arr[j+1] = arr[j];
               j = j - 1;
           }
           arr[j + 1] = key;
         }
         cout << "Insertion Finished" << endl;
       }
};

class BubbleSort : public Sort
{
public:
    void sort()
    {
        int i, j;
        for (i = 0; i < n-1; i++)
        {
            for (j = 0; j < n-i-1; j++)
            {
                if (arr[j] > arr[j+1])
                   swap(&arr[j], &arr[j+1]);
             }
         }
         cout << "Bubble Finished" << endl;
       }
};

class SelectionSort : public Sort
{
public:
    void sort()
    {
        int i, j, min;
        for (i = 0; i < n-1; i++)
        {
            min = i; 
            for (j = i+1; j < n; j++)
            {
                if (arr[j] < arr[min])
                min = j;
            }
                swap(&arr[min], &arr[i]);
        }
        cout << "Selection Finished" << endl;
    }
};