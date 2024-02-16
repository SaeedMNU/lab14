#include <iostream>
#include <ctime>

class Stopwatch {
private:
    clock_t starttime;

public:
    void start() {
        starttime = clock();
    }

    double stop() {
        clock_t endtime = clock();
        return static_cast<double>(endtime - starttime) / CLOCKS_PER_SEC;
    }
};

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    const int size = 10000;
    int arr[size];

    // Fill the array with random values
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000;
    }

    Stopwatch timer;
    timer.start();

    // Time-consuming operation (selection sort)
    selectionSort(arr, size);

    double elapsed_time = timer.stop();
    std::cout << "Elapsed time for sorting: " << elapsed_time << " seconds" << std::endl;

    return 0;
}
