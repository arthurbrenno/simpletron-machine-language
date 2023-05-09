#include "s_instruction_handler.h"
int ExtractOperation(int& instruction) {
	return instruction / 100;
}

int ExtractOperand(int& instruction) {
	return instruction % 100;
}

int GetDigits(int instruction) {
	int digits{};
	while (instruction > 0) {
		instruction /= 10;
		digits++;
	}
	return digits;
}
