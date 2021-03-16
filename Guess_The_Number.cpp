#include <iostream>
#include <cstdlib>
#include <ctime>

void play_game();

int main()
{
    srand(time(NULL)); // to avoid always getting the same random numbers
    int choice;

    do {
        std::cout << "0. Quit" << std::endl << "1. Play game" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
            case 0:
                std::cout << "Thanks for playing!" << std::endl;
                return 0;
            case 1:
                play_game();
                break;
        }
    } while (choice != 0);

}

void play_game()
{
    int random_number = rand() % 51;
    int guess_number;
    int attempts = 5;
    
    while (1) 
    {
        if (attempts == 0) 
        {
            std::cout << "\nYou ran out of attempts, sorry! :(\n" << std::endl;
            return;
        }

        std::cout << "\nRemaining attempts: " << attempts << std::endl;
        std::cout << "Guess the number: ";
        std::cin >> guess_number;

        if (guess_number == random_number) 
        {
            std::cout << "\nYou win!\n" << std::endl;
            return;
        } else if (guess_number < random_number)
        {
            std::cout << "Too low" << std::endl;
            attempts--;
        } else 
        {
            std::cout << "Too high" << std::endl;
            attempts--;
        }        
    }
}