#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

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

void print_array_elements(std::array<int, 10> &arrayCpp)
{
    for (int i : arrayCpp)
    {
        cout << i << " ";
    }
    cout << endl;
}

void print_vector_elements(std::vector<int> &vectorCpp)
{
    for (int i : vectorCpp)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int array[DIM] = {20, 50, -10, -40, 80, -30, 70, 55, 75, 5};
    std::array<int, 10> arrayCpp = {20, 50, -10, -40, 80, -30, 70, 55, 75, 5};
    std::vector vectorCpp = {20, 50, -10, -40, 80, -30, 70, 55, 75, 5}; //<int> non serve perché lo deduce da solo, perché di fatti sarebbe grigio nell'IDE
    std::vector vectorCpp2(vectorCpp.begin(), vectorCpp.end()); //costruttore di vector, passando l'inizio e la fine di un altro array e crea una copia
    vectorCpp.push_back(-100); //aggiunge un elemento alla fine del vector

    std::sort(arrayCpp.begin(), arrayCpp.end()); //begin ed end sono iterator, prendono l'elemento iniziale e l'elemento finale. Sort prende gli elementi e ordina ciò che c'è tra gli elementi
    //std::sort(arrayCpp.begin() + 5, arrayCpp.end()); //ordina solo dalla posizione 5 alla fine
    //std::sort(arrayCpp.begin(), arrayCpp.end() - 5); //ordina solo dall'inizio fino a 5 posizioni prima della fine
    std::sort(vectorCpp2.begin(), vectorCpp2.end());

    vectorCpp.pop_back(); //rimuove l'ultimo elemento del vector

    cout << "Array ordinato con std::array e std::sort: " << endl;
    print_array_elements(arrayCpp);
    cout << "Array ordinato con std::vector: " << endl;
    print_vector_elements(vectorCpp2);

    //ordinamento invers
    std::sort(vectorCpp.begin(), vectorCpp.end()); //prima di invertire devo ordinare, altrimenti inverte l'ordine originale, che è casuale
    std::reverse(vectorCpp.begin(), vectorCpp.end());
    //std::sort(vectorCpp.begin(), vectorCpp.end(), std::greater<>()); //prima di invertire devo ordinare, greater<>() è un comparatore che ordina in modo decrescente
    //std::sort(arrayCpp.rbegin(), arrayCpp.rend());
    //std::sort(vectorCpp.rbegin(), vectorCpp.rend());

     cout << "Scrivi il numero che vuoi cercare:" << endl;
    int numeroDaCercare;
    cin >> numeroDaCercare;

    auto risultato = std::find_if(vectorCpp.begin(), vectorCpp.end(), [numeroDaCercare](int x)
    {
        if (x == numeroDaCercare)
            return true;
        return false;
    }); //find_if fa un ciclo finché non trova il primo elemento che soddisfa la condizione. utilizzo una funzione lambda (funzione che non esiste al di furoi del find_if) che restituisce true se l'elemento è == a 50. find_if restituisce un iterator che vale vectorCpp.end() + 1 se non trova nulla. le [] servono per passare variabili esterne alla lambda

    cout << "Elemento trovato con find_if: " << *risultato << endl; //devo dereferenziare l'iterator per ottenere il valore, sono come dei puntatori

    cout << "Array ordinato in modo inverso con std::vector: " << endl;
    print_vector_elements(vectorCpp);

    quickSort(array);
    int multipli10 = contaMultipli10(array, DIM);
    bool isNonNegative = nonNegative(array, DIM);

    cout << "Array ordinato: " << endl;
    for (int i : array)
    {
        cout << i << " ";
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

/*
    void bubbleSort(int array[], int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
        }
    }
 */