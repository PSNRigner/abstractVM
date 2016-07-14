//
// Exceptions.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 11:08:58 2016 loic frasse-mathon
// Last update Thu Jul 14 11:18:27 2016 loic frasse-mathon
//

#include "Exceptions.hh"

SyntaxException::SyntaxException() throw ()
{
}

SyntaxException::~SyntaxException() throw ()
{
}

const char	*SyntaxException::what() const throw ()
{
  return "/!\\ Syntax Error /!\\";
}

UnknownInstructionException::UnknownInstructionException() throw ()
{
}

UnknownInstructionException::~UnknownInstructionException() throw ()
{
}

const char	*UnknownInstructionException::what() const throw ()
{
  return "/!\\ Unknown Instruction /!\\";
}

OverflowException::OverflowException() throw ()
{
}

OverflowException::~OverflowException() throw ()
{
}

const char	*OverflowException::what() const throw ()
{
  return "/!\\ Overflow Exception /!\\";
}

UnderflowException::UnderflowException() throw ()
{
}

UnderflowException::~UnderflowException() throw ()
{
}

const char	*UnderflowException::what() const throw ()
{
  return "/!\\ Underflow Exception /!\\";
}

EmptyStackException::EmptyStackException() throw ()
{
}

EmptyStackException::~EmptyStackException() throw ()
{
}

const char	*EmptyStackException::what() const throw ()
{
  return "/!\\ Empty stack /!\\";
}

DivByZeroException::DivByZeroException() throw ()
{
}

DivByZeroException::~DivByZeroException() throw ()
{
}

const char	*DivByZeroException::what() const throw ()
{
  return "/!\\ Division by Zero /!\\";
}

NoExitException::NoExitException() throw ()
{
}

NoExitException::~NoExitException() throw ()
{
}

const char	*NoExitException::what() const throw ()
{
  return "/!\\ No Exit at end of commands /!\\";
}

AssertException::AssertException() throw ()
{
}

AssertException::~AssertException() throw ()
{
}

const char	*AssertException::what() const throw ()
{
  return "/!\\ Assertion failed /!\\";
}

StackOperandException::StackOperandException() throw ()
{
}

StackOperandException::~StackOperandException() throw ()
{
}

const char	*StackOperandException::what() const throw ()
{
  return "/!\\ Not enough stack elements for operand/!\\";
}
