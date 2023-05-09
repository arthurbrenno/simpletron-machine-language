#include "s_operations.h"
#include <iostream>

/*A dump after executing a Simpletron program would show
the actual values of instructions and data values at
the moment execution terminated.*/
void Dump(
	int memory[], 
	int m_size, 
	int& eax, 
	int& icounter, 
	int& iregister, 
	int& opcode, 
	int& operand) {
	
	printf("REGISTERS: \n");
	printf("accumulator: %+05d\n", eax);
	printf("instructionCounter: %02d\n", icounter);
	printf("instructionRegister: %+05d\n", iregister);
	printf("operationCode: %02d\n", opcode);
	printf("operand: %02d\n", operand);

	//divide by 10 to go from 0 to 9
	printf("          0     1     2     3     4     5     6     7     8     9\n");	
	//having problems to align this... here is an unnoptimized version
	for (int i{0}; i < m_size; ++i) {
		if (i % 10 == 0) {
			if (i == 0) {
				printf("%d    ", i);
			}
			else {
				printf("%d   ", i);
			}
		}
		if (i < 10) {
			printf(" %+05d", memory[i]);
		}
		else if (i < 100) {
			printf(" %+05d", memory[i]);
		}
		else {
			printf("%+05d ", memory[i]);
		}
		if (i % 10 == 9) {
			printf("\n");
		}
	}
}
