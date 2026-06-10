// Copyright 2025 NNTU-CS
#include "alg.h"

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int leftSide = 0;
    int rightSide = len - 1;
    int count = 0;

    while (leftSide < rightSide) {
        int sum = arr[leftSide] + arr[rightSide];
        if (sum == value) {
            if (arr[leftSide] == arr[rightSide]) {
                int n = rightSide - leftSide + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int leftCount = arr[leftSide];
            int rightDuplic = arr[rightSide];
            int leftIndx = leftSide;
            int lcount = 0;
            while (leftIndx <= rightSide && arr[leftIndx] == leftCount) {
                lcount++;
                leftIndx++;
            }
            int rightIndx = rightSide;
            int rcount = 0;
            while (rightIndx >= leftSide && arr[rightIndx] == rightDuplic) {
                rcount++;
                rightIndx--;
            }
            count += lcount * rcount;
            leftSide += lcount;
            rightSide -= rcount;
        } else if (sum < value) {
            leftSide++;
        } else {
            rightSide--;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {

    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int target = value - arr[i];

        if (target < arr[i]) {
            break;
        }

        int leftSide = i + 1;
        int rightSide = len - 1;
        int firstPos = -1;

        while (leftSide <= rightSide) {
            int mid = leftSide + (rightSide - leftSide) / 2;
            if (arr[mid] == target) {
                firstPos = mid;
                rightSide = mid - 1;
            } else if (arr[mid] < target) {
                leftSide = mid + 1;
            } else {
                rightSide = mid - 1;
            }
        }

        if (firstPos == -1) {
            continue;
        }

        leftSide = firstPos;
        rightSide = len - 1;
        int lastPos = firstPos;

        while (leftSide <= rightSide) {
            int mid = leftSide + (rightSide - leftSide) / 2;
            if (arr[mid] == target) {
                lastPos = mid;
                leftSide = mid + 1;
            } else if (arr[mid] < target) {
                leftSide = mid + 1;
            }else {
                rightSide = mid - 1;
            }
        }

        if (arr[i] == target) {
            int n = lastPos - i + 1;
            count += n * (n - 1) / 2;
            break;
        }

        int leftCount = 1;
        while (i + leftCount < len && arr[i + leftCount] == arr[i]) {
            leftCount++;
        }

        count += leftCount * (lastPos - firstPos + 1);
    }
    return count;
}
