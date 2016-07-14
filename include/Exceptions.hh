//
// Exceptions.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 09:25:19 2016 loic frasse-mathon
// Last update Thu Jul 14 11:08:32 2016 loic frasse-mathon
//

#ifndef EXCEPTIONS_HH_
# define EXCEPTIONS_HH_

# include <exception>
# include <string>

class		SyntaxException : public std::exception
{
public:
  SyntaxException() throw ();
  virtual ~SyntaxException() throw ();
  virtual const char		*what() const throw ();
};

class		UnknownInstructionException : public std::exception
{
public:
  UnknownInstructionException() throw ();
  virtual ~UnknownInstructionException() throw ();
  virtual const char		*what() const throw ();
};

class		OverflowException : public std::exception
{
public:
  OverflowException() throw ();
  virtual ~OverflowException() throw ();
  virtual const char		*what() const throw ();
};

class		UnderflowException : public std::exception
{
public:
  UnderflowException() throw ();
  virtual ~UnderflowException() throw ();
  virtual const char		*what() const throw ();
};

class		EmptyStackException : public std::exception
{
public:
  EmptyStackException() throw ();
  virtual ~EmptyStackException() throw ();
  virtual const char		*what() const throw ();
};

class		DivByZeroException : public std::exception
{
public:
  DivByZeroException() throw ();
  virtual ~DivByZeroException() throw ();
  virtual const char		*what() const throw ();
};

class		NoExitException : public std::exception
{
public:
  NoExitException() throw ();
  virtual ~NoExitException() throw ();
  virtual const char		*what() const throw ();
};

class		AssertException : public std::exception
{
public:
  AssertException() throw ();
  virtual ~AssertException() throw ();
  virtual const char		*what() const throw ();
};

class		StackOperandException : public std::exception
{
public:
  StackOperandException() throw ();
  virtual ~StackOperandException() throw ();
  virtual const char		*what() const throw ();
};

#endif /* !EXCEPTIONS_HH_ */
