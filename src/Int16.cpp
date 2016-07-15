//
// Int16.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:51:03 2016 loic frasse-mathon
// Last update Fri Jul 15 13:54:04 2016 loic frasse-mathon
//

#include <cstdlib>
#include <sstream>
#include "Int16.hh"
#include "Exceptions.hh"

Int16::Int16(const std::string &string)
{
  __int128	n = atol(string.c_str());
  if (n > 32767)
    throw new OverflowException;
  if (n < -32768)
    throw new UnderflowException;
  this->data = (short)n;
}

Int16::~Int16()
{
}

std::string		Int16::toString() const
{
  std::ostringstream	oss;
  std::string		tmp;

  oss << (int)data;
  tmp = oss.str();
  return (tmp);
}

eOperandType::eOperandType	Int16::getType() const
{
  return (eOperandType::Int16);
}

IOperand	*Int16::operator+(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op + *this);
  long	value = (short)atoi(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int16(tmp));
}

IOperand	*Int16::operator-(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op - *this);
  long	value = (short)atoi(op.toString().c_str()) - this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int16(tmp));
}

IOperand	*Int16::operator*(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op * *this);
  long	value = (short)atoi(op.toString().c_str()) * this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int16(tmp));
}

IOperand	*Int16::operator/(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op / *this);
  long	value = (short)atoi(op.toString().c_str()) / this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int16(tmp));
}

IOperand	*Int16::operator%(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op % *this);
  long	value = (short)atoi(op.toString().c_str()) % this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int16(tmp));
}
