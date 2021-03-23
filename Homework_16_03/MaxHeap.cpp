#include <iostream>
using namespace std;

struct MaxHeap
{
    int * array;
    int size;
    int maxSize;

    MaxHeap(int maxSize)
    {
        this->maxSize = maxSize;
        size = -1;
        array = new int [maxSize];
    }

    int Parent(int i){ return (i - 1) / 2; }
    int LeftChild(int i){ return 2 * i + 1; }
    int RightChild(int i){ return 2 * i + 2; }

    void SiftUp(int i)
    {
        while (i > 0 && array[i] > array[Parent(i)])
        {
            int temp = array[Parent(i)];
            array[Parent(i)] = array[i];
            array[i] = temp;
            i = Parent(i);
        }
    }

    void SiftDown(int i)
    {
        int maxIndex = i;
        if (array[LeftChild(i)] > array[i]){ maxIndex = LeftChild(i); }
        else if (array[RightChild(i)] > array[i]){ maxIndex = RightChild(i); }
        if (maxIndex != i)
        {
            int temp = array[maxIndex];
            array[maxIndex] = array[i];
            array[i] = temp;
            SiftDown(maxIndex);
        }
    }

    void Insert(int p)
    {
        if (size < maxSize - 1)
        {
            size++;
            array[size] = p;
            SiftUp(size);
        }
        else
        {
            size++;
            NewHeap(p);
        }
    }

    int ExtractMax()
    {
        int result = array[0];
        array[0] = array[size];
        array[size] = result;
        size--;
        SiftDown(0);
        return result;
    }

    void NewHeap(int p)
    {
        int * new_array = new int [maxSize * 2];
        for (int i = 0; i < maxSize; i++)
        {
            new_array[i] = array[i];
        }
        new_array[size] = p;
        maxSize *= 2;
        array = new_array;
        delete new_array;
        SiftUp(size);
    }

    void PrintAll()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << array[i] << endl;
        }
    }
};

int main()
{
    MaxHeap * arr = new MaxHeap(4);
    arr->Insert(7);
    arr->Insert(9);
    arr->Insert(5);
    arr->Insert(10);
    arr->PrintAll();
    return 0;
}
