#include <iostream>

int main()
{
    // Allocate memory for an integer using 'new'
    int *number = new int;
    float *num = new float;

    // Assign a value to the dynamically allocated memory
    *number = 42;
    *num = 42.42;

    // Print the value
    std::cout << "Value: " << *number << std::endl;
    std::cout << "Value: " << *num << std::endl;

    // Calculate the size of the allocated memory in bytes
    size_t sizeOfNumber = sizeof(*number);
    size_t sizeOfNum = sizeof(*number);

    // Print the size of the allocated memory
    std::cout << "Size of int dynamically allocated memory: " << sizeOfNumber << " bytes" << std::endl;
    std::cout << "Size of float dynamically allocated memory: " << sizeOfNum << " bytes" << std::endl;

    // Deallocate the memory using 'delete'
    delete number;
    delete num;

    return 0;
}
