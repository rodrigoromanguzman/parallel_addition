#include <omp.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 1000; // Define un tamaño constante para los arreglos

using namespace std;

int main() {
    int array1[SIZE], array2[SIZE], resultArray[SIZE];

    // Inicializamos el generador de numeros aleatoreos
    srand(time(NULL));

    // Inicializamos array1 and array2 con valores aleatoreos
    for (int i = 0; i < SIZE; ++i) {
        array1[i] = rand() % 100;  // Entre 0 and 99
        array2[i] = rand() % 100;  // Entre 0 and 99
    }
    // Imprimir array1
    cout << "Array 1: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << array1[i] << " ";
    }
    cout << endl;

    // Imprimir array2
    cout << "Array 2: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << array2[i] << " ";
    }
    cout << endl;

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int chunk_size = SIZE / omp_get_num_threads(); //Dividimos el trabajo entre hilos

        int start = tid * chunk_size;
        int end = start + chunk_size;

        for (int i = start; i < end; ++i) {
            resultArray[i] = array1[i] + array2[i];
        }
    }

    // Imprimimos el resultado
    cout << "Arreglo resultante: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << resultArray[i] << " ";
    }
    cout << endl;

    return 0;
}