#include "memory_handler.h"

bool Write(int& value, int& position, int mem[], int msize) {
	if (position > msize || position < 0) {
		return true;
	}
	mem[position] = value;
	return true;
}
