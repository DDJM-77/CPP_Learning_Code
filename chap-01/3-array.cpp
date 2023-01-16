#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cerr << "Error in the command line" << std::endl;
        return -1;
    }
    int array_size = std::stoi(argv[1]);
    if (array_size <= 0)
    {
        std::cerr << "Expected strictly positive value for array size." << std::endl;
        return -1;
    }
    std::cout << array_size << std::endl;
    std::vector<int> array;

    for (int i = 0; i < 4; i++)
    {
        array.emplace_back(i);
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout << array[i] << std::endl;
    }
    return 0;
}
