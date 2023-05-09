///////////////////////////////////////////////////////////////////
// NAME:               operations.h
//
// PURPOSE:            Define constants for all operations
//                     of Simpletron
//
// FUNCTIONS/OBJECTS:  CFooBar
//
// AUTHOR:             Arthur Brenno
///////////////////////////////////////////////////////////////////

#ifndef SIMPLETRON_HEADER_OPERATIONS_H
#define SIMPLETRON_HEADER_OPERATIONS_H

namespace Simpletron {
	
	/*
	* input and output constants (10 => 11) *
	*/
	namespace io {
		
		//Read a word from the keyboard into a specific location in memory
		constexpr int read = 10;

		//Write a word from a specific location in memory to the screen.
		constexpr int write = 11;

	}

	/*
	* Load/store constants (20 => 21)*
	*/
	namespace ls {

		//Load a word from a specific location in memory into the accumulator
		constexpr int load = 20;
		
		//Store a word from the accumulator into a specific location in memory
		constexpr int store = 21;

	}

	/*
	* Arithmetic constants (30 => 33) *
	*/
	namespace arithmetic {

		//Add a word from a specific location in memory to the word in the accumulator
		constexpr int add{ 30 };
		
		//Subtract a word from a specific location in memory from the word in the accumulator
		constexpr int sub{ 31 };

		//Divide a word from a specific location in memory into the word in the accumulator
		constexpr int div{ 32 };

		//Multiply a word from a specific location in memory by the word in the accumulator
		constexpr int imul{ 33 };

		//Get the remainder
		constexpr int mod{ 34 };

		//Elevate
		constexpr int exp{ 35 };
		
	}

	/*
	* Transfer-of-control constants (40 => 43) *
	*/
	namespace toc {
		
		//Branch to a specific location in memory
		constexpr int branch = 40;

		//Branch to a specific location in memory if the accumulator is negative.
		constexpr int branchneg = 41;

		//Branch to a specific location in memory if the accumulator is zero.
		constexpr int branchzero = 42;

		//Halt. The program has completed its task.
		constexpr int halt = 43;

	}

}

void Dump(int memory[], int m_size, int& eax, int& icounter, int& iregister, int& opcode, int& operand);

#endif
