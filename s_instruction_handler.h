#ifndef SIMPLETRON_HEADER_INSTRUCTION_HANDLER_H
#define SIMPLETRON_HEADER_INSTRUCTION_HANDLER_H

// get first two digits of an instruction (READ/WRITE/LOAD...)
int ExtractOperation(int& instruction);

// get last two digits of an instruction (memory position)
int ExtractOperand(int& instruction);

// check if it has 4 digits
int GetDigits(int instruction);

#endif