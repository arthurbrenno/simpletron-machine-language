///////////////////////////////////////////////////////////////////
// NAME:               memory_hadler.h
//
// PURPOSE:            Perform basic manipulation with arrays that are
//                     emulating the memory of Simpletron.
//
// FUNCTIONS/OBJECTS:  CFooBar
//
// AUTHOR:             Arthur Brenno
///////////////////////////////////////////////////////////////////


#ifndef SIMPLETRON_HEADER_MEMORYHANDLER_H
#define SIMPLETRON_HEADER_MEMORYHANDLER_H

// write a value to a specific location of the memory
bool Write(int& value, int& position, int mem[], int msize);

#endif

