#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool step(std::vector<int>&, int);

int main()
{
    // read input
    std::string line;
    std::cin >> line;

    // process into vector of opcodes
    std::stringstream ss(line);
    std::string opcode_str;
    int item;
    std::vector<int> memory;
    while (std::getline(ss, opcode_str, ','))
    {
        item = std::stoi(opcode_str);
        memory.push_back(item);
    }

    // run the program
    for (auto pc = 0; step(memory, pc); pc += 4);

    // print the result at location 0
    std::cout << memory[0] << std::endl;

    return EXIT_SUCCESS;
}

bool step(std::vector<int>& memory, int pc)
{
    // halt at 99
    if (memory[pc] == 99) return false;

    int opcode = memory[pc];
    int operand1 = memory[memory[pc + 1]];
    int operand2 = memory[memory[pc + 2]];
    int destination = memory[pc + 3];

    if (opcode == 1)
    {
        memory[destination] = operand1 + operand2;
    }
    else if (opcode == 2)
    {
        memory[destination] = operand1 * operand2;
    }

    return true;
}