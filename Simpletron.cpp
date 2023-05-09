/* ************************************************************
	Simpletron v1.0
	Author: Arthur Brenno, 2023
	github: arthurbrenno
	public release date: 2023-05-09

	Changes:
	2023-05-06: started the main code
	2023-05-09 alpha program DONE. no bugs found yet.
 ************************************************************ */

#include <iostream>
#include <string>
#include "s_operations.h"
#include "s_instruction_handler.h"
#include "s_specs.h"
#if defined _WIN32
#define Clear() system("cls")
#else
#define Clear() system("clear")
#endif

void WelcomeMessage();
void LoadingComplete();
bool AskForInteger(const std::string& input, int& destination);

int main() {
	
	WelcomeMessage();
	int memory[mem_size]{};						//Memory of the machine
	
	//Fill the memory with instructions
	for (int i{ 0 }; i < mem_size; ++i) {
		int current_instruction{};
		bool success{};
		
		while (
			(GetDigits(current_instruction) != qtd_digits
			&& current_instruction != stop_sentinel) 
			|| !success) {

			printf("%02d ? ", i);
			std::string input{};
			std::cin >> input;
			success = AskForInteger(input, current_instruction);
		}
		
		memory[i] = current_instruction;
		
		if (current_instruction == stop_sentinel 
			|| ExtractOperation(current_instruction) == Simpletron::toc::halt) { break; }

	}

	Clear();
	LoadingComplete();

	int instruction_counter{};
	int instruction_register{};
	int operation_code{};
	int operand{};
	int eax{};
	while (instruction_register != stop_sentinel 
		&& ExtractOperation(instruction_register) != Simpletron::toc::halt) {
		
		instruction_register = memory[instruction_counter];
		operation_code = ExtractOperation(instruction_register);
		operand = ExtractOperand(instruction_register);
		switch (operation_code) {
		case Simpletron::io::read: {
			bool success{};
			int integer{};
			while (!success) {
				std::cout << "Enter an Integer: ";
				std::string temp;
				std::cin >> temp;
				success = AskForInteger(temp, integer);
			}
			memory[operand] = integer;
			instruction_counter++; break;
		}
		case Simpletron::io::write: {
			std::cout << memory[operand] << std::endl; instruction_counter++; break;
		}
		case Simpletron::ls::load: {
			eax = memory[operand]; instruction_counter++; break;
		}
		case Simpletron::ls::store: {
			memory[operand] = eax; instruction_counter++; break;
		}
		case Simpletron::arithmetic::add: {
			eax += memory[operand]; instruction_counter++; break;
		}
		case Simpletron::arithmetic::sub: {
			eax -= memory[operand]; instruction_counter++; break;
		}
		case Simpletron::arithmetic::div: {
			eax /= memory[operand]; instruction_counter++; break;
		}
		case Simpletron::arithmetic::imul: {
			eax *= memory[operand]; instruction_counter++; break;
		}
		case Simpletron::arithmetic::mod: {
			eax %= memory[operand]; instruction_counter++; break;
		}
		case Simpletron::arithmetic::exp: {
			eax = std::pow(eax, memory[operand]); instruction_counter++; break;
		}
		case Simpletron::toc::branch: {
			instruction_counter = operand; break;
		}
		case Simpletron::toc::branchneg: {
			if (eax < 0) { instruction_counter = operand; break; }
			instruction_counter++; break;
		}
		case Simpletron::toc::branchzero: {
			if (eax == 0) { instruction_counter = operand; break; }
			instruction_counter++; break;
		}
		case Simpletron::toc::halt: {
			system("exit"); break;
		}
		default:
			instruction_counter++;
		}
	}

	Dump(
		memory, 
		sizeof(memory) / sizeof(memory[0]), 
		eax, instruction_counter, 
		instruction_register, 
		operation_code, 
		operand);
	std::cout << std::endl;
	system("pause");
}

//first program message
void WelcomeMessage() {
	std::cout << "*** Welcome to Simpletron! ***" << '\n';
	std::cout << "*** Please enter your program one instruction ***" << '\n';
	std::cout << "*** (or data word) at a time. I will display ***" << '\n';
	std::cout << "*** the location number and a question mark (?). ***  ***" << '\n';
	std::cout << "*** You then type the word for that location. ***" << '\n';
	std::cout << "*** Type -99999 to stop entering your program. ***" << '\n';
}

//instruction loading complete
void LoadingComplete() {
	std::cout << "***Program loading completed ***" << '\n' 
	<< "***Program execution begins***" << '\n';
}

//Get a valid integer input
bool AskForInteger(const std::string& input, int& destination) {
	try {
		int temp{ std::stoi(input) };
		destination = temp;
		return true;
	}
	catch (const std::exception e) { return false; }
}

