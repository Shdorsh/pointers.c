# Pointers.c

*The result of a little research into pointers, stack and heap*

This library facilitates pointer usage with the pointer union type, which easily allows to convert most type of pointer into an unsigned long, or another type of pointer. No type conversion needed.

Furthermore, it allows you to dive into the stack with **stack_down**, aligning the pointer automatically. **stack_search** allows you to check for a value in memory with the same size as specified.
The similarities between pointer values can be also looked up with **compare_pointer_values** to assure you got a fitting char/int/long.
