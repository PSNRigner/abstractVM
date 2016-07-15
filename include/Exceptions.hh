//
// Exceptions.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 09:25:19 2016 loic frasse-mathon
// Last update Fri Jul 15 14:42:07 2016 loic frasse-mathon
//

#ifndef EXCEPTIONS_HH_
# define EXCEPTIONS_HH_

# include <exception>
# include <string>

class		VMException : public std::exception
{
private:
  const char			*str;
protected:
  VMException(const char *) throw ();
  virtual ~VMException() throw ();
public:
  virtual const char		*what() const throw ();
};

class		SyntaxException : public VMException
{
public:
  SyntaxException() throw ();
  virtual ~SyntaxException() throw ();
};

class		UnknownInstructionException : public VMException
{
public:
  UnknownInstructionException() throw ();
  virtual ~UnknownInstructionException() throw ();
};

class		OverflowException : public VMException
{
public:
  OverflowException() throw ();
  virtual ~OverflowException() throw ();;
};

class		UnderflowException : public VMException
{
public:
  UnderflowException() throw ();
  virtual ~UnderflowException() throw ();
};

class		EmptyStackException : public VMException
{
public:
  EmptyStackException() throw ();
  virtual ~EmptyStackException() throw ();
};

class		DivByZeroException : public VMException
{
public:
  DivByZeroException() throw ();
  virtual ~DivByZeroException() throw ();
};

class		NoExitException : public VMException
{
public:
  NoExitException() throw ();
  virtual ~NoExitException() throw ();
};

class		AssertException : public VMException
{
public:
  AssertException() throw ();
  virtual ~AssertException() throw ();
};

class		StackOperandException : public VMException
{
public:
  StackOperandException() throw ();
  virtual ~StackOperandException() throw ();
};

class		EmptyRegistryException : public VMException
{
public:
  EmptyRegistryException() throw ();
  virtual ~EmptyRegistryException() throw ();
};

class		NotYetSupportedException : public VMException
{
public:
  NotYetSupportedException() throw ();
  virtual ~NotYetSupportedException() throw ();
};

#endif /* !EXCEPTIONS_HH_ */
