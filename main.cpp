#include <iostream>

using namespace std;

const int DIM = 10;

void quickSortHelper(int array[], int start, int end)
{
    if (start < end)
    {
        int pivot = array[end];
        int i = start - 1;
        for (int j = start; j < end; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                swap(array[i], array[j]);
            }
        }
        swap(array[i + 1], array[end]);
        int posPivot = i + 1;
        quickSortHelper(array, start, posPivot - 1);
        quickSortHelper(array, posPivot + 1, end);
    }
}

void quickSort(int array[])
{
    quickSortHelper(array, 0, DIM - 1);
}

int contaMultipli10(int array[], int dim)
{
    int count = 0;
    for (int i = 0; i < dim; i++)
    {
        if (array[i] % 10 == 0)
        {
            count++;
        }
    }
    return count;
}

bool nonNegative(int array[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        if (array[i] < 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int array[DIM] = {20, 50, -10, -40, 80, -30, 70, 55, 75, 5};
    quickSort(array);
    int multipli10 = contaMultipli10(array, DIM);
    bool isNonNegative = nonNegative(array, DIM);
    cout << "Array ordinato: " << endl;
    for (int i = 0; i < DIM; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Multipli di 10: " << multipli10 << endl;
    if (isNonNegative)
    {
        cout << "Tutti i numeri sono non negativi." << endl;
    }
    else
    {
        cout << "Ci sono numeri negativi nell'array." << endl;
    }
    return 0;
}