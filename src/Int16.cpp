//
// Int16.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:51:03 2016 loic frasse-mathon
// Last update Thu Jul 14 11:31:11 2016 loic frasse-mathon
//

#include <cstdlib>
#include <sstream>
#include "Int16.hh"
#include "Exceptions.hh"

AInt16::AInt16(const std::string &string)
{
  __int128	n = atol(string.c_str());
  if (n > 32767)
    throw new OverflowException;
  if (n < -32768)
    throw new UnderflowException;
  this->data = (short)n;
}

AInt16::~AInt16()
{
}

std::string		AInt16::toString() const
{
  std::ostringstream	oss;
  std::string		tmp;

  oss << (int)data;
  tmp = oss.str();
  return (tmp);
}

eOperandType	AInt16::getType() const
{
  return (Int16);
}

IOperand	*AInt16::operator+(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op + *this);
  long	value = (short)atoi(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt16(tmp));
}

IOperand	*AInt16::operator-(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op - *this);
  long	value = (short)atoi(op.toString().c_str()) - this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt16(tmp));
}

IOperand	*AInt16::operator*(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op * *this);
  long	value = (short)atoi(op.toString().c_str()) * this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt16(tmp));
}

IOperand	*AInt16::operator/(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op / *this);
  long	value = (short)atoi(op.toString().c_str()) / this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt16(tmp));
}

IOperand	*AInt16::operator%(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op % *this);
  long	value = (short)atoi(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt16(tmp));
}
