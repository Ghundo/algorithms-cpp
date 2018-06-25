/* CountingSort: Sorts a range of integers [0...n] by counting how many times
 * each unique value appears in an array, and using arithmetic to determine
 * the position of each value in the output array.
 *
 * Time complexity: O(n+k)
 * Space complexity: O(k)
 *
 * The running time of this algorithm is based on the number of items and the
 * difference between the maximum and minimum values, so it is only recommended
 * to use in cases where the variation in values is not significantly greater
 * than the number of items.
 *
 * n = number of items.
 * k = maximum value.
 */

#include <iomanip>
#include <iostream>
#include <algorithm>

int* counting_sort(int input[], int n, int k) {
    int frequencies[k + 1] = {};

    for (int i = 0; i < n; i++) {
        frequencies[input[i]]++;
    }

    for (int i = 1; i <= k; i++) {
        frequencies[i] += frequencies[i - 1];
    }

    int* sorted_arr = new int[n]();
    for (int i = 0; i < n; i++) {
        sorted_arr[frequencies[input[i]] - 1] = input[i];
        frequencies[input[i]]--;
    }

    return sorted_arr;
}

int main() {
    int data[] = {0, 4, 4, 1, 6, 3, 7, 7, 7, 9, 15};
    int N = sizeof(data) / sizeof(data[0]);
    int K = *std::max_element(data, data + N);

    int* sorted_arr = counting_sort(data, N, K);

    // Show output.
    std::cout << " Input Data: ";
    for (int i = 0; i < N; i++) {
        std::cout << std::setw(2) << data[i] << " ";
    }
    std::cout << "\n     Sorted: ";
    for (int i = 0; i < N; i++) {
        std::cout << std::setw(2) << sorted_arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
