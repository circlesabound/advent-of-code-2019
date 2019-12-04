#include <cstdlib>
#include <iostream>
#include <string>

int getFuel(int);

int main()
{
    int totalFuel = 0;
    for (std::string line; std::getline(std::cin, line);)
    {
        auto mass = std::stoi(line);
        totalFuel += getFuel(mass);
    }

    std::cout << totalFuel << std::endl;

    return EXIT_SUCCESS;
}

int getFuel(int mass)
{
    // Divide by 3 automatically rounding down, then subtract 2
    auto fuel = mass / 3 - 2;
    if (fuel <= 0) return 0;
    else return fuel + getFuel(fuel);
}