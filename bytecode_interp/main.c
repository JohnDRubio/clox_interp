#include "common.h"
#include "chunk.h"
#include "debug.h"

/**
 * Goal of this project is to write a bytecode interpreter
 * 
 * What is a bytecode interpreter?
 * 
 *  Imagine a gradient - on the left side is a tree interpreter (recursive descent interpreter)
 *  and on the right side is a compiler.
 * 
 *  A recursive-descent interpreter traverses an abstract syntax tree and performs
 *  operations accoring to the node being examined. While a tree interpreter is relatively
 *  simple to implement, one tradeoff is performance. Each node in the AST is allocated
 *  on the heap. An issue with this is that dynamically sequential instructions may not
 *  be cached together since heap allcoations do not guarantee contiguousness.
 * 
 *  On the other end of the gradient is a compiler. The goal of a compiler is to
 *  generate optimized machine code. By definition, when a program that has been
 *  generated by the compiler is loaded into RAM, the instructions are next to one
 *  another. This is another difference between compilers and interpreters because
 *  an interpreter is the program loaded into memory which then executes source programs
 *  line by line.
 * 
 *  The motivation behind a bytecode interpreter is a desire to gain better performance
 *  than a tree interpreter without the hassle of writing a compiler (and also writing
 *  platform-specific code as opposed to platform-independent code which is what the
 *  bytecode interpreter would generate).
 *  
*/

int main(int argc, const char* argv[]) {
  Chunk chunk;
  initChunk(&chunk);

  int constant = addConstant(&chunk, 1.2);  // The consant value 1.2 is added to chunk's constant pool
  writeChunk(&chunk, OP_CONSTANT);  // Tells interpreter that next byte in chunk is the index of the constant value
  writeChunk(&chunk, constant);     // The index of the consant value
  writeChunk(&chunk, OP_RETURN);

  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  return 0;
}
