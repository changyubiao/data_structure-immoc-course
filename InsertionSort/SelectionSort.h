//
// Created by frank on 2020/1/5.
//

#ifndef INSERTIONSORT_SELECTIONSORT_H
#define INSERTIONSORT_SELECTIONSORT_H


template<typename T>
void selectSort(T arr[], T len) {

    for (int i = 0; i < len; i++) {
        int minIndex = i;

        for (int j = i + 1; j < len; j++) {

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }


        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
        }

    }

}


#endif //INSERTIONSORT_SELECTIONSORT_H
