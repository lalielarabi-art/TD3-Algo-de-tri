#include <iostream>
#include <vector>

int search(std::vector<int> &vec, int val){
    int indice{-1};
    size_t left{0};
    size_t right{vec.size()};
    

    while(left<right){
    size_t middle{(left+right)/2};

    if (vec[middle]==val){
        return middle;
    }
    else if(vec[middle]<val){
        left=middle + 1;
    }

    else{
        right=middle;
    }
}
    return -1;
}

int main(){
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int val{10};
    int result=search(array,val);

    if (result==-1)
    {
        std::cout<<"La valeur "<< val <<" n'est pas dans le tableau."<<std::endl;
    }
    else
    {
        std::cout<<"La valeur "<< val <<" est dans le tableau à l'indice "<< result<<std::endl;
    }
    for (std::size_t i {0}; i < array.size(); i++)
    {
        std::cout << array[i] << std::endl;
    }

}
