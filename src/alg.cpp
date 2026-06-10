// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    if (len <= 1) return 0;
    std::sort(arr, arr + len);
    int count = 0;
    int leftSide = 0;
    int rightSide = len - 1;

    while (leftSide < rightSide) {
        int sum = arr[leftSide] + arr[rightSide];
        if (sum == value) {
            int leftCount = 1;
            int rightCount = 1;

            while (leftSide + leftCount < rightSide &&
                arr[leftSide] == arr[leftSide + leftCount]) {
                leftCount++;
            }

            while (rightSide - rightCount > leftSide &&
                arr[rightSide] == arr[rightSide - rightCount]) {
                rightCount++;
            }

            if (arr[leftSide] == arr[rightSide]) {
                count += leftCount * (leftCount - 1) / 2;
            } else {
                count += leftCount * rightCount;
            }

            leftSide += leftCount;
            rightSide -= rightCount;
        } else if (sum < value) {
            leftSide++;
        } else {
            rightSide--;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    if (len <= 1) return 0;
    std::sort(arr, arr + len);
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int leftSide = i + 1;
        int rightSide = len - 1;
        bool found = false;
        int firstPos = -1;

        while (leftSide <= rightSide) {
            int mid = leftSide + (rightSide - leftSide) / 2;
            if (arr[mid] == target) {
                found = true;
                firstPos = mid;
                rightSide = mid - 1;
            } else if (arr[mid] < target) {
                leftSide = mid + 1;
            } else {
                rightSide = mid - 1;
            }
        }

        if (found) {
            int countTarget = 0;
            int j = firstPos;
            while (j < len && arr[j] == target) {
                countTarget++;
                j++;
            }
            count += countTarget;
        }
    }
    return count;
}
