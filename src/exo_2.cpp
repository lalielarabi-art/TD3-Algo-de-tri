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



void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right){

    std::vector<int> vec1(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> vec2(vec.begin() + middle + 1, vec.begin() + right + 1);

    int i{0};
    int j{0};
    size_t k{left};
    while (i<vec1.size() and j<vec2.size()){
        if (vec1[i]<vec2[j]){
            vec[k++]=vec1[i];   //on ajoute l'élément de vec1
            i+=1;
        }
        else{
            vec[k++]=vec2[j]; //on ajoute l'élément de vec2
            j+=1;
        }
    }
    if (i==vec1.size())
    {
        for (int l{j};l<vec2.size();++l){
            vec[k++]=vec2[l];          //vec1 est vide ont rempli avec le reste de vec2
        }
    }
    if (j==vec2.size())
    {
        for (int l{i};l<vec1.size();++l){
        vec[k++]=vec1[l];     //vec2 est vide ont rempli avec le reste de vec1
        }
    }



}

void merge_sort(std::vector<int> & vec, size_t const left, size_t const right){
    if (right-left>=1){
        merge_sort(vec, left, (right+left)/2);
        merge_sort(vec,((right+left)/2)+1,right);
        merge_sort_merge(vec,left, (right+left)/2,right);     
}
}



void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}
int main(){
    ScopedTimer timer("temps");
    std::vector<int> array = generate_random_vector(10000,10);
    merge_sort(array);

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