#include <cstdlib>
#include <iostream>

using namespace std;

void print(int numbers[], int size);
void countingSort(int numbers[], int size);

int main(int argc, char *argv[]) {
    int numbers[] = {1, 2, 9, 9, 8, 7, 12, 6, 4, 3, 1, 2};
    int size = sizeof(numbers) / sizeof(*numbers);

    print(numbers, size);
    countingSort(numbers, size);
    print(numbers, size);

    system("read");
    return EXIT_SUCCESS;
}

void print(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

void countingSort(int numbers[], int size) {
    int min = numbers[0], max = numbers[0];

    for (int i = 0; i < size; i++)
        if (numbers[i] < min)
            min = numbers[i];
        else if (numbers[i] > max)
            max = numbers[i];

    int *list = new int[max - min + 1] ();

    for (int i = 0; i < size; i++)
        list[numbers[i] - min]++;

    for (int i = 0, j = 0; i < size; i++) {
        while (!(list[j]--))
            j++;

        numbers[i] = j + min;
    }

    delete [] list;
}
