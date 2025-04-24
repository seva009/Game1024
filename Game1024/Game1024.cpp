#include <cstdlib>
#include <iostream>

int current_power = 10;

int main()
{
	start:
    std::cout << "It's game 1024 you need to guess random number between 1 and " << (int)std::pow(2,current_power) << " within 10 tries\n";
    std::cout << "If you guess the number in 10 tries you win\n";
	std::cout << "Current difficulty is " << current_power - 10 << "\n";
    srand(time(NULL)); // Инициализация генератора случайных чисел
    int randomNumber = rand() % (int)std::pow(2, 10) + 1; // Генерация случайного числа от 1 до 1024
    int guess;
    int tries = 0;
    for (; tries < 10; tries++)
	{
		std::cout << "Enter your guess: ";
		std::cin >> guess;
		if (guess == randomNumber)
		{
			std::cout << "Congratulations! You guessed the number in " << tries << " tries.\n";
			break;
		}
		else if (guess < randomNumber)
		{
			std::cout << "Too low! Try again.\n";
		}
		else
		{
			std::cout << "Too high! Try again.\n";
		}
	}
	if (tries == 10)
	{
		std::cout << "Sorry! You've used all your tries. The number was " << randomNumber << ".\n";
		current_power = 9; // dirty hack
	}
	std::cout << "Do you want to play again? (y/n): ";
	char playAgain;
	std::cin >> playAgain;
	if (playAgain == 'y' || playAgain == 'Y')
	{
		current_power++; // Увеличиваем сложность на 1
		goto start; // Запуск игры заново
	}
	else
	{
		std::cout << "Thanks for playing!\n";
	}
	return 0;
}