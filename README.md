# smartsticks
Code for running patterns on the smartstick project

#### Recommended visual studio "Filters" for code organization:

- Commands/
- Images/
- Input/
- Modes/

#### Adding a new serial command
To add a new serial command, there are several steps.

- Create a new class (probably in a new .cpp/.h pair) which subclasses one of `SerialCommand`, `ISerialCommand`, `OSerialCommand`, or `IOSerialCommand`
- The only mandatory method to define is Run(), which must return one of the `CommandState` enum values
- Add a new opcode for the command to the Opcodes enum in `SerialCommand.h`
- Add an instantiation of the class to the commandList vector in CommandInterface's constructor
- Add a case statement handling the new opcode under `CommandInterface::OpenState`

At this point, you should have a command which can be handled and responded to by the framework.

##### Command execution and IO
To take input, you subclass either `ISerialCommand` or `IOSerialCommand` (if you also produce output to be sent back over the wire), and then define a `ParseByte(byte input)` method in your class. Your Run() method will probably immediately return `COMMAND_READ` so that it can be fed bytes.

To produce output, you subclass either `OSerialCommand` or `IOSerialCommand`, and define a constructor which saves a pointer to the CommandInterface's output buffer. During the course of the command's execution, it can write to the buffer, which will be sent back at the end of the command's execution if `COMMAND_RESPOND` is sent.

