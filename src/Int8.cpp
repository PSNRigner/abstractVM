//
// Int8.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:51:03 2016 loic frasse-mathon
// Last update Thu Jul 14 11:31:19 2016 loic frasse-mathon
//

#include <cstdlib>
#include <sstream>
#include "Int8.hh"
#include "Exceptions.hh"

AInt8::AInt8(const std::string &string)
{
  __int128	n = atol(string.c_str());
  if (n > 127)
    throw new OverflowException;
  if (n < -128)
    throw new UnderflowException;
  this->data = (char)n;
}

AInt8::~AInt8()
{
}

std::string		AInt8::toString() const
{
  std::ostringstream	oss;
  std::string		tmp;

  oss << (int)data;
  tmp = oss.str();
  return (tmp);
}

eOperandType	AInt8::getType() const
{
  return (Int8);
}

IOperand	*AInt8::operator+(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op + *this);
  long	value = (char)atoi(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt8(tmp));
}

IOperand	*AInt8::operator-(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op - *this);
  long	value = (char)atoi(op.toString().c_str()) - this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt8(tmp));
}

IOperand	*AInt8::operator*(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op * *this);
  long	value = (char)atoi(op.toString().c_str()) * this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt8(tmp));
}

IOperand	*AInt8::operator/(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op / *this);
  long	value = (char)atoi(op.toString().c_str()) / this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt8(tmp));
}

IOperand	*AInt8::operator%(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op % *this);
  long	value = (char)atoi(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt8(tmp));
}
