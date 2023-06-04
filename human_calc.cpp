#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    int firstRandomNumber = rand() % 10 + 1;
    int secondRandomNumber = rand() % 10 + 1;
    int sum = firstRandomNumber + secondRandomNumber;
    int answer;
    int tries = 0;
    bool found = false;

    while (!found)
    {
        std::cout << "What is " << firstRandomNumber << " + " << secondRandomNumber << std::endl;
        std::cin >> answer;
        tries++;

        if (answer == sum)
        {
            std::cout << "Congratulations, your a great human calculator! "
                      << "The sum is " << sum << " and it only took you " << tries << " tries." << std::endl;
            found = true;
        }
        else
        {
            std::cout << "Sorry, that's wrong, try again." << std::endl;
        }
    }

    return 0;
}