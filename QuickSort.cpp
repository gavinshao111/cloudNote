#include <iostream>

void quicksort(int src[], int first, int last);

template<class T>
void print_array(const T src[], const size_t& num);

int main(int argc, char* argv[]) {
    int src[13] = {9, 5, 11, 56, 14, 66, 80, 6, 17, 46, 23, 61, 95};

    print_array(src, 13);
    quicksort(src, 0, 12);

    return 0;
}

void quicksort(int src[], int first, int last) {
    if (first < last) {
        int i = first;
        int j = last;
        int x = src[i];

        while (i < j) {
            while (i < j && x <= src[j]) //从j往前找比x小的值
                --j;
            if (i < j)
                src[i] = src[j];

            while (i < j && x >= src[i]) //从i往后找比x大的值
                ++i;
            if (i < j)
                src[j] = src[i];
        }
        src[i] = x;
        
        print_array(src, 13);
        
        quicksort(src, first, i - 1);
        quicksort(src, j + 1, last);
    }
}

template<class T>
void print_array(const T src[], const size_t& num) {
    int i = 0;
    for (; i < num; ++i)
        std::cout << src[i] << ' ';
    std::cout << '\n';
}