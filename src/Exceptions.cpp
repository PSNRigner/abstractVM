//
// Exceptions.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 11:08:58 2016 loic frasse-mathon
// Last update Fri Jul 15 14:40:24 2016 loic frasse-mathon
//

#include "Exceptions.hh"

VMException::VMException(const char *str) throw ()
  : str(str)
{
}

VMException::~VMException() throw ()
{
}

const char	*VMException::what() const throw ()
{
  return (this->str);
}

SyntaxException::SyntaxException() throw ()
  : VMException("/!\\ Syntax Error /!\\")
{
}

SyntaxException::~SyntaxException() throw ()
{
}

UnknownInstructionException::UnknownInstructionException() throw ()
  : VMException("/!\\ Unknown Instruction /!\\")
{
}

UnknownInstructionException::~UnknownInstructionException() throw ()
{
}

OverflowException::OverflowException() throw ()
  : VMException("/!\\ Overflow Exception /!\\")
{
}

OverflowException::~OverflowException() throw ()
{
}

UnderflowException::UnderflowException() throw ()
  : VMException("/!\\ Overflow Exception /!\\")
{
}

UnderflowException::~UnderflowException() throw ()
{
}

EmptyStackException::EmptyStackException() throw ()
  : VMException("/!\\ Empty stack /!\\")
{
}

EmptyStackException::~EmptyStackException() throw ()
{
}

DivByZeroException::DivByZeroException() throw ()
  : VMException("/!\\ Division by Zero /!\\")
{
}

DivByZeroException::~DivByZeroException() throw ()
{
}

NoExitException::NoExitException() throw ()
  : VMException("/!\\ No Exit at end of commands /!\\")
{
}

NoExitException::~NoExitException() throw ()
{
}

AssertException::AssertException() throw ()
  : VMException("/!\\ Assertion failed /!\\")
{
}

AssertException::~AssertException() throw ()
{
}

StackOperandException::StackOperandException() throw ()
  : VMException("/!\\ Not enough stack elements for operand/!\\")
{
}

StackOperandException::~StackOperandException() throw ()
{
}

EmptyRegistryException::EmptyRegistryException() throw ()
  : VMException("/!\\ Empty register slot /!\\")
{
}

EmptyRegistryException::~EmptyRegistryException() throw ()
{
}

NotYetSupportedException::NotYetSupportedException() throw ()
  : VMException("/!\\ Not Yet Supported /!\\")
{
}

NotYetSupportedException::~NotYetSupportedException() throw ()
{
}
