#include <iostream>
#include <vector>
#include <algorithm>
bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }



void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right){

    std::vector<int> vec1(vec[left], vec[middle]);
    std::vector<int> vec2(vec[middle +1] , vec[right]);
    for (std::size_t k {0}; k < vec.size(); k++){
    for (std::size_t i {0}; i < vec1.size(); i++){
        for (std::size_t j {0}; j < vec2.size(); j++){
            if(vec1[i]<vec2[j]){
                vec[k]=vec1[i];
            }        
            else{
                vec[k]=vec2[j];
                
            }
        }

    }
}
}



void merge_sort(std::vector<int> & vec, size_t const left, size_t const right){
    if (right-left>1){
        merge_sort(vec, left, (right+left)/2);
        merge_sort(vec,((right+left)/2)+1,right);
        merge_sort_merge(vec,left, (right+left)/2,right);     
}
}



void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}
int main(){
    std::vector<int> array {1, 52, 5, 15, 60, 7, 27, 6};
    merge_sort(array);

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