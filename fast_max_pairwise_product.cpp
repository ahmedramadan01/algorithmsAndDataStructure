#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int n = numbers.size();
    int first_largest = 0;
    int second_largest = 0;
    int index1 = 0;
    int index2 = 0;
    for (int first = 0; first < n; ++first) {
        if(numbers[first] > first_largest){
            first_largest = numbers[first];
            index1 = first;
        }
    }

    //std::cout << first_largest << "\n" << index1 <<"\n";

    for(int second = 0; second < n; ++second) {
        if(numbers[second] > second_largest && second != index1){
            second_largest = numbers[second];
            index2 = second;
        }

    }

    //std::cout << second_largest << "\n" << index2 <<"\n";

    return (long long)first_largest * second_largest;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(2 * pow(10.0,5.0) + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    //for(int i= 0; i <= 2*pow(10.0,5.0); ++i){
      //  numbers[i] = i;
    //}
    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
