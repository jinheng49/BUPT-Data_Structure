#include <stdio.h>

int searchRotatedArray(int nums[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int num_keys;
    scanf("%d,", &num_keys);

    int nums[num_keys];
    char ch;
    for (int i = 0; i < num_keys; ++i) {
        scanf("%d%c", &nums[i],&ch);
    }

    int target;
    scanf("%d", &target);

    int result = searchRotatedArray(nums, num_keys, target);
    printf("%d", result);

    return 0;
}