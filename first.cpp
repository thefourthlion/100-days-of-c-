/*
This line includes the input/output stream library,
which provides functionality for reading and writing to the console.
*/
#include <iostream>

/*
This includes the C standard library, which provides general-purpose
functions, including memory allocation and random number generation.
*/
#include <cstdlib>

/*
This includes the C time library, which
provides functions for working with dates and times.
*/
#include <ctime>

/*
This line begins the definition of the main
function, which is the entry point of the program.
*/
int main()
{
    srand(time(0)); // Seed the random number generator with time(0)

    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int tries = 0;
    bool found = false;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    while (!found)
    {
        std::cout << "Enter your guess (1-100): ";
        std::cin >> guess;
        tries++;

        if (guess == secretNumber)
        {
            found = true; // end while loop
            // standard output logging winning msg
            std::cout << "Congratulations! You guessed the number in " << tries << " tries." << std::endl;
        }
        else if (guess < secretNumber)
        {
            std::cout << "Too low! Try again." << std::endl;
        }
        else
        {
            std::cout << "Too high! Try again." << std::endl;
        }
    }

    return 0;
}
