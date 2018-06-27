/* Binary count: Counts the number of occurrence of X in the given sorted array
 * through binary search application.
 *
 * Time complexity: O(log n)
 *
 * A = input array.
 * N = number of items.
 * X = value to search.
 */

#include <iostream>

int binary_count(const int A[], const int N, const int X) {
    int l, m, r;
    int first = -1, last = -1;

    for (int i = 0 ; i < 2; i++) {
        l = 0;
        r = N - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if(A[m] == X) {
                if (i == 0) {
                    first = m;
                    r = m - 1;
                } else {
                    last = m;
                    l = m + 1;
                }
            } else if (A[m] < X) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }
    return last - first + 1;
}

int main() {
    // Input should be in ascending order.
    int input[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    int N = sizeof(input) / sizeof(input[0]);

    int i = binary_count(input, N, 3);

    std::cout << i << std::endl;

    return 0;
}
