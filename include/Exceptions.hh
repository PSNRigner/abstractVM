//
// Exceptions.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 09:25:19 2016 loic frasse-mathon
// Last update Thu Jul 14 09:35:16 2016 loic frasse-mathon
//

#ifndef EXCEPTIONS_HH_
# define EXCEPTIONS_HH_

# include <exception>
# include <string>

class		SyntaxException : public std::exception
{
public:
  SyntaxException(int, const std::string &) throw ();
  ~SyntaxException() throw ();
  virtual const char		*what() const throw ();
};

class		UnknownInstructionException : public std::exception
{
public:
  UnknownInstructionException(int, const std::string &) throw ();
  ~UnknownInstructionException() throw ();
  virtual const char		*what() const throw ();
};

class		OverflowException : public std::exception
{
public:
  OverflowException(int, const std::string &) throw ();
  ~OverflowException() throw ();
  virtual const char		*what() const throw ();
};

class		UnderflowException : public std::exception
{
public:
  UnderflowException(int, const std::string &) throw ();
  ~UnderflowException() throw ();
  virtual const char		*what() const throw ();
};

class		EmptyStackException : public std::exception
{
public:
  EmptyStackException(int, const std::string &) throw ();
  ~EmptyStackException() throw ();
  virtual const char		*what() const throw ();
};

class		DivByZeroException : public std::exception
{
public:
  DivByZeroException(int, const std::string &) throw ();
  ~DivByZeroException() throw ();
  virtual const char		*what() const throw ();
};

class		NoExitException : public std::exception
{
public:
  NoExitException(int, const std::string &) throw ();
  ~NoExitException() throw ();
  virtual const char		*what() const throw ();
};

class		AssertException : public std::exception
{
public:
  AssertException(int, const std::string &) throw ();
  ~AssertException() throw ();
  virtual const char		*what() const throw ();
};

class		StackOperandException : public std::exception
{
public:
  StackOperandException(int, const std::string &) throw ();
  ~StackOperandException() throw ();
  virtual const char		*what() const throw ();
};

#endif /* !EXCEPTIONS_HH_ */
