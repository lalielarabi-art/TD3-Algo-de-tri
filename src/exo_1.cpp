#include <iostream>
#include <vector>
#include <algorithm>
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }


void selection_sort(std::vector<int> & vec){
    for (std::size_t i {0}; i < vec.size(); i++){
        size_t indexmin {i};
        for (std::size_t j {i}; j < vec.size(); j++){
                if (vec[j]<vec[indexmin]){
                    indexmin=j;
                }
        }

        std::swap(vec[indexmin], vec[i]);  
    }


}

int main(){
    ScopedTimer timer("temps");
    std::vector<int> array = generate_random_vector(10000,10);

    selection_sort(array);

    if (is_sorted(array)) {
    std::cout << "Le tableau est trié" << std::endl;
    } else {
    std::cout << "Le tableau n'est pas trié" << std::endl;
    }
    /*/for (std::size_t i {0}; i < array.size(); i++)
        {
            std::cout << array[i] << std::endl;
        }/*/
}

