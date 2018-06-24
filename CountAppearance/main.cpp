/* Count how many times each number appears in an input.
 *
 * Time complexity: O(n)
 *
 * This algorithm is only recommended in cases where the input size is small
 * because the memory will depend on biggest number in the input.
 */

#include <iostream>

void get_appearances(int input_arr[], int output_arr[], int datasize) {
    for (int i = 0; i < datasize; i++) {
        output_arr[input_arr[i]]++;
    }
}

int main() {
    int data[] = {0, 4, 4, 1, 6, 3, 7, 7, 7, 9};
    int n = sizeof(data) / sizeof(data[0]);
    int appearance_arr[n] = {};

    get_appearances(data, appearance_arr, n);

    // Show output.
    std::cout << " Input Data: ";
    for (int i = 0; i < n; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\nNumber Line: ";
    for (int i = 0; i < n; i++) {
        std::cout << i << " ";
    }
    std::cout << "\nAppearances: ";
    for (int i = 0; i < n; i++) {
        std::cout << appearance_arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
