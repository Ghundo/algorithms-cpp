/* Counting sort: Sorts an array of integers by counting how many times each
 * unique value appeared and using arithmetic to determine the position of each
 * value in the output array.
 *
 * The running time of this algorithm is based on the number of items and the
 * difference between the maximum and minimum values, so it is only recommended
 * to use in cases where the variation in values is not significantly greater
 * than the number of items.
 *
 * Time complexity: O(n+k)
 * Space complexity: O(k)
 *
 * A = input array.
 * N = number of items.
 * K = maximum value.
 */

#include <iomanip>
#include <iostream>
#include <algorithm>

int* counting_sort(const int A[], const int N, const int K) {
    int frequencies[K + 1] = {};

    for (int i = 0; i < N; i++) {
        frequencies[A[i]]++;
    }

    for (int i = 1; i <= K; i++) {
        frequencies[i] += frequencies[i - 1];
    }

    int* sorted_arr = new int[N]();
    for (int i = 0; i < N; i++) {
        sorted_arr[frequencies[A[i]] - 1] = A[i];
        frequencies[A[i]]--;
    }

    return sorted_arr;
}

int main() {
    int input[] = {0, 4, 4, 1, 6, 3, 7, 7, 7, 9, 15};
    int N = sizeof(input) / sizeof(input[0]);
    int K = *std::max_element(input, input + N);

    int* sorted_arr = counting_sort(input, N, K);

    // Show output.
    std::cout << " Input Data: ";
    for (int i = 0; i < N; i++) {
        std::cout << std::setw(2) << input[i] << " ";
    }
    std::cout << "\n     Sorted: ";
    for (int i = 0; i < N; i++) {
        std::cout << std::setw(2) << sorted_arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
