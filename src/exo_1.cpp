#include <iostream>
#include <vector>
#include <algorithm>
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
std::vector<int> array {1, 52, 5, 15, 60, 7, 27, 6};

selection_sort(array);

if (is_sorted(array)) {
std::cout << "Le tableau est trié" << std::endl;
} else {
std::cout << "Le tableau n'est pas trié" << std::endl;
}
for (std::size_t i {0}; i < array.size(); i++)
    {
        std::cout << array[i] << std::endl;
    }
}

