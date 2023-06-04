#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0)); // Seed the random number generator

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
            found = true;
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
