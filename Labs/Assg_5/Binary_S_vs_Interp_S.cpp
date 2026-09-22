/*Generate a list of 10000000 (ten million) random numbers with C++. Use the Binary Search
and the Interpolation Search to find a key. Measure and report the execution time for each
search.*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;


// =====================================================
// BINARY SEARCH
// =====================================================

int binarySearch(const vector<int>& arr, int key) {

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}


// =====================================================
// INTERPOLATION SEARCH
// =====================================================

int interpolationSearch(const vector<int>& arr, int key) {

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high &&
           key >= arr[low] &&
           key <= arr[high]) {

        if (arr[high] == arr[low]) {

            if (arr[low] == key)
                return low;

            return -1;
        }

        long long pos =
            low +
            ((long long)(key - arr[low]) *
            (high - low)) /
            (arr[high] - arr[low]);


        if (arr[pos] == key) {
            return pos;
        }

        if (arr[pos] < key) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }

    return -1;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    const int N = 10000000;


    vector<int> arr(N);


    // Random number generator
    mt19937 rng(random_device{}());

    uniform_int_distribution<int> dist(1, 10000000);


    cout << "Generating "
         << N
         << " random numbers..." << endl;


    for (int i = 0; i < N; i++) {
        arr[i] = dist(rng);
    }


    // Sort the array
    cout << "Sorting array..." << endl;

    sort(arr.begin(), arr.end());


    // Select a random key from the array
    uniform_int_distribution<int>
        keyDist(0, N - 1);

    int key = arr[keyDist(rng)];


    cout << "Key: "
         << key
         << endl;


    // =================================================
    // BINARY SEARCH
    // =================================================

    auto startBinary =
        chrono::high_resolution_clock::now();


    int binaryPosition =
        binarySearch(arr, key);


    auto endBinary =
        chrono::high_resolution_clock::now();


    auto binaryTime =
        chrono::duration_cast<
            chrono::microseconds
        >(endBinary - startBinary);


    // =================================================
    // INTERPOLATION SEARCH
    // =================================================

    auto startInterpolation =
        chrono::high_resolution_clock::now();


    int interpolationPosition =
        interpolationSearch(arr, key);


    auto endInterpolation =
        chrono::high_resolution_clock::now();


    auto interpolationTime =
        chrono::duration_cast<
            chrono::microseconds
        >(endInterpolation -
          startInterpolation);


    // =================================================
    // RESULTS
    // =================================================

    cout << "\n========== RESULTS ==========\n";


    cout << "\nBinary Search\n";

    cout << "Position: "
         << binaryPosition
         << endl;

    cout << "Execution time: "
         << binaryTime.count()
         << " microseconds"
         << endl;


    cout << "\nInterpolation Search\n";

    cout << "Position: "
         << interpolationPosition
         << endl;

    cout << "Execution time: "
         << interpolationTime.count()
         << " microseconds"
         << endl;


    return 0;
}