//
// Int32.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:51:03 2016 loic frasse-mathon
// Last update Thu Jul 14 11:30:59 2016 loic frasse-mathon
//

#include <cstdlib>
#include <sstream>
#include "Int32.hh"
#include "Exceptions.hh"

AInt32::AInt32(const std::string &string)
{
  __int128	n = atol(string.c_str());
  if (n > 2147483647)
    throw new OverflowException;
  if (n < -2147483648)
    throw new UnderflowException;
  this->data = (int)n;
}

AInt32::~AInt32()
{
}

std::string		AInt32::toString() const
{
  std::ostringstream	oss;
  std::string		tmp;

  oss << data;
  tmp = oss.str();
  return (tmp);
}

eOperandType	AInt32::getType() const
{
  return (Int32);
}

IOperand	*AInt32::operator+(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op + *this);
  long	value = (int)atoi(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt32(tmp));
}

IOperand	*AInt32::operator-(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op - *this);
  long	value = (int)atoi(op.toString().c_str()) - this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt32(tmp));
}

IOperand	*AInt32::operator*(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op * *this);
  long	value = (int)atoi(op.toString().c_str()) * this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt32(tmp));
}

IOperand	*AInt32::operator/(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op / *this);
  long	value = (int)atoi(op.toString().c_str()) / this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt32(tmp));
}

IOperand	*AInt32::operator%(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op % *this);
  long	value = (int)atoi(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AInt32(tmp));
}
