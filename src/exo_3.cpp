#include <iostream>
#include <vector>
#include <algorithm>
#include "ScopedTimer.hpp"



std::vector<int> generate_random_vector(size_t const size, int const max = 10000) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


int main(){
    ScopedTimer timer("temps");

    std::vector<int> array = generate_random_vector(10000,10);
    std::sort(array.begin(), array.end());

}

/*/ Après plusieurs essais pour 100 éléments 
L‘algorithme de tri itératif prend environ 0.035ms et le tri récursif environ 0.08ms.
On remarque que l'algorithme de la bibliothèque standard est vraiment plus rapide que les deux autres, environ 0.005 ms. 

Pour 10000 éléments, l'algorithme de la bibliothèque standard reste aussi de loin le plus rapide, environ 0.3ms. 
L‘algorithme de tri itératif prend environ 150ms et le tri récursif se situe plutôt aux alentours de 8ms.
Danc ce cas, l'itératif devient vraiment beaucoup plus lent.

CONCLUSION:
Pour 100 éléments:
Les différences se voient mais sont faibles car sur un petit tableau la complexité compte peu.

Par contre pour 10000 éléments:
On remarque bien que le tri itératif O(n**2) devient environ 20 fois plus lent que le récursif O(nlog(n)).
Et l'algorithme de la bibliothèque standard reste de loin le plus optimisé./*/



