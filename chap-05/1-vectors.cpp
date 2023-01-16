#include <iostream>
#include <utility>
#include <vector>

void display_array(const std::vector<int>& array)
{
    for (auto elem : array)
    {
        std::cout << elem << std::endl;
    }
}

int main()
{
    auto array_one = std::vector<int> { 4, 0 };
    auto array_two = std::vector<int>(4, 0);

    std::cout << "The first one" << std::endl;
    display_array(array_one); // displays a single "4" and a single "0"

    std::cout << "The other one" << std::endl;
    display_array(array_two); // displays four "0" value

    std::cout << "Thanks to primitive array" << std::endl;
    int  array[]                    = { 0, 1, 2, 3, 4, 5 };
    int* it_begin                   = &array[0];
    int* it_end                     = &array[5];
    auto vector_thanks_to_primitive = std::vector<int>(
        it_begin, it_end); // On utilise la syntaxe () car on evite le constructeur par défaut
    auto vector_thanks_to_primitive_full = std::vector<int>(array, array + 6); // Autre syntaxe

    display_array(vector_thanks_to_primitive);
    std::cout << "Thanks to primitive array full" << std::endl;
    display_array(vector_thanks_to_primitive_full);

    // Swap contents
    std::cout << "Swap" << std::endl;
    for (size_t left = 0, right = vector_thanks_to_primitive_full.size() - 1; left < right; ++left, --right)
    {
        std::swap(vector_thanks_to_primitive_full[left], vector_thanks_to_primitive_full[right]);
    }
    display_array(vector_thanks_to_primitive_full);

    // Duplication
    std::cout << "Duplication" << std::endl;
    for (auto it = vector_thanks_to_primitive_full.begin(); it != vector_thanks_to_primitive_full.end();
         it += 2)
    {
        it = vector_thanks_to_primitive_full.insert(
            it,
            *it); // on doit réassigner à it l'élément insérer pour éviter l'invalidation de l'itérateur quand
                  // on passe par une fonction de réallocation du tableau
    }
    display_array(vector_thanks_to_primitive_full);

    // Suppression
    std::cout << "Supression" << std::endl;
    while (!vector_thanks_to_primitive_full.empty())
    {
        vector_thanks_to_primitive_full.pop_back();
    }
    display_array(vector_thanks_to_primitive_full);

    // Suppression 2 à 6
    std::cout << "Suppression Interval" << std::endl;
    auto vect = std::vector<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vect.erase(vect.begin() + 2, vect.begin() + 7); // Supprime des indices 2 à 6
    display_array(vect);

    // Find
    std::cout << "Suppression de l'élément 9" << std::endl;
    const auto it = std::find(vect.begin(), vect.end(), 9);
    if (it != vect.end()) // Vérifie que ce n'est pas la valeur de fin d'itérateur (on a trouvé aucun élément)
    {
        vect.erase(it);
    }
    display_array(vect);

    // Réassignation
    std::vector<int> v;
    v.assign(5, 2);
    v.assign({ 0, 2, 32, -4, 3 });
    v.clear();

    return 0;
}