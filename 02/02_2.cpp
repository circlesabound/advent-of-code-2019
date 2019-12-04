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

    std::vector<int> memory_copy;
    for (int noun = 0; noun <= 99; ++noun)
    {
        for (int verb = 0; verb <= 99; ++verb)
        {
            // take a copy of the original memory
            // modify the starting parameters
            memory_copy = memory;
            memory_copy[1] = noun;
            memory_copy[2] = verb;

            // run the program
            for (auto pc = 0; step(memory_copy, pc); pc += 4);

            // check result
            if (memory_copy[0] == 19690720)
            {
                std::cout << 100 * noun + verb << std::endl;
                return EXIT_SUCCESS;
            }
        }
    }

    std::cerr << "uh oh" << std::endl;
    return EXIT_FAILURE;
}

bool step(std::vector<int>& memory, int pc)
{
    // halt at 99
    if (memory[pc] == 99) return false;

    int opcode = memory[pc];
    int addr1 = memory[pc + 1];
    int addr2 = memory[pc + 2];
    int destination = memory[pc + 3];
    if (addr1 >= memory.size() ||
        addr2 >= memory.size() ||
        destination >= memory.size()) return false;
    int operand1 = memory[addr1];
    int operand2 = memory[addr2];

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