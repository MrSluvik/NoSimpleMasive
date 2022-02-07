// Написати функцію, яка отримує покажчик на динамічний масив і його розмір.Функція має видалити з масиву всі прості числа та повернути покажчик на новий динамічний масив.
#include<iostream>
#include <cmath>
#include <ctime>
using namespace std;
void inputArr(int* A, int size) {//ф-н заповнення рандомними числами
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 20;
    }
}
void printArr(int* arr, int size) {//функція виводу масивів 
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\t";
        }
}
bool prostae_chislo(int n) {//ф-н провірки чи просте число
    bool result(true);

    if ((n == 2) || (n == 3))
        result = true;
    else {
        for (int i = 2; i <= floor(sqrt(n)); ++i)
            if (n % i == 0)
            {
                result = false;
                break;
            }
    }
    return (result && (n != 1));
}
void proverca(int* A, int size) {//ф-н провірки чи елемент масиву не простий та його запису у новий масив
    int c = 0;//лічильник
    for (int i = 0; i < size; ++i) {
        if (!prostae_chislo(A[i])) {
            ++c;
        }
    }    
    int* newArr = new int[c];

    int l = 0;
    for (int i = 0; i < size; ++i) {
        if (!prostae_chislo(A[i])) {
            newArr[l++] = A[i];
        }
    }
    for (int i = 0; i < c; i++) {
        cout << newArr[i] << "\t";
    }
    A = newArr;
    delete[] newArr;   
}
int main()
{
    setlocale(0, "");
    srand(time(NULL));
    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;
    int* A = new int[size];    
    cout << "Заповнення масиву: \n";
    inputArr( A,size); // ф - н заповнення рандомними числами
    printArr(A, size);//ф-н друку масиву 
    cout << endl;
    proverca(A, size);//ф-н провірки чи елемент масиву не простий та його запису у новий масив

    delete[]A;//видаленя дин.масиву
   
   
}






