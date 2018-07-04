/* Binary search first: Searches for the first occurrence of X in a given sorted
 * array through binary search application.
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 *
 * A = input array.
 * N = number of items.
 * X = value to search.
 */

/**
 *    author: marcavenzaid
 *    created: 2018-06-28-15.38
 */

#include <iostream>

int binary_search_first(const int A[], const int N, const int X) {
    int l = 0, m, r = N - 1;
    int first = - 1;

    while (l <= r) {
        m = (l + r) / 2;
        if(A[m] == X) {
            first = m;
            r = m - 1;
        } else if (A[m] < X) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return first;
}

int main() {
    // Input should be in ascending order.
    int input[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    int N = sizeof(input) / sizeof(input[0]);

    int i = binary_search_first(input, N, 3);

    std::cout << i << std::endl;

    return 0;
}
