#include <iostream>
#include <vector>


std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


int max_(std::vector<int> & vec){
    int max{0};
    for (std::size_t i {0}; i < vec.size(); i++){
        if(vec[i]>max){
            max=vec[i];
        }
    }
    return max;
}

void counting_sort(std::vector<int> & vec){

    int max=max_(vec);
    std::vector<int>  occurence ;

    for (std::size_t i {0}; i < max+1; i++){
        occurence.push_back(0);
    } 

    for (std::size_t i {0}; i < vec.size(); i++){
        occurence[vec[i]]+=1;
    } 

    int pointeur{0};
    for (std::size_t i {0}; i < occurence.size(); i++){
       for(int j{0}; j<occurence[i];++j){
        vec[pointeur]=i;
        pointeur+=1;

        }
    } 
    
   
}

int main(){
    std::vector<int> array = generate_random_vector(20,10);
    for (std::size_t i {0}; i < array.size(); i++)
    {
        std::cout << array[i] << std::endl;
        
    }
    std::cout<<"//"<<std::endl;

    
    counting_sort(array);

    for (std::size_t i {0}; i < array.size(); i++)
    {
        std::cout << array[i] << std::endl;
    }
}