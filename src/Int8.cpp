//
// Int8.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:51:03 2016 loic frasse-mathon
// Last update Fri Jul 15 13:53:52 2016 loic frasse-mathon
//

#include <cstdlib>
#include <sstream>
#include "Int8.hh"
#include "Exceptions.hh"

Int8::Int8(const std::string &string)
{
  __int128	n = atol(string.c_str());
  if (n > 127)
    throw new OverflowException;
  if (n < -128)
    throw new UnderflowException;
  this->data = (char)n;
}

Int8::~Int8()
{
}

std::string		Int8::toString() const
{
  std::ostringstream	oss;
  std::string		tmp;

  oss << (int)data;
  tmp = oss.str();
  return (tmp);
}

eOperandType::eOperandType	Int8::getType() const
{
  return (eOperandType::Int8);
}

IOperand	*Int8::operator+(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op + *this);
  long	value = (char)atoi(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int8(tmp));
}

IOperand	*Int8::operator-(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op - *this);
  long	value = (char)atoi(op.toString().c_str()) - this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int8(tmp));
}

IOperand	*Int8::operator*(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op * *this);
  long	value = (char)atoi(op.toString().c_str()) * this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int8(tmp));
}

IOperand	*Int8::operator/(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op / *this);
  long	value = (char)atoi(op.toString().c_str()) / this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int8(tmp));
}

IOperand	*Int8::operator%(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op % *this);
  long	value = (char)atoi(op.toString().c_str()) % this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int8(tmp));
}
