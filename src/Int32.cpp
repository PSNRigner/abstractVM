//
// Int32.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:51:03 2016 loic frasse-mathon
// Last update Fri Jul 15 11:18:54 2016 loic frasse-mathon
//

#include <cstdlib>
#include <sstream>
#include "Int32.hh"
#include "Exceptions.hh"

Int32::Int32(const std::string &string)
{
  __int128	n = atol(string.c_str());
  if (n > 2147483647)
    throw new OverflowException;
  if (n < -2147483648)
    throw new UnderflowException;
  this->data = (int)n;
}

Int32::~Int32()
{
}

std::string		Int32::toString() const
{
  std::ostringstream	oss;
  std::string		tmp;

  oss << data;
  tmp = oss.str();
  return (tmp);
}

eOperandType::eOperandType	Int32::getType() const
{
  return (eOperandType::Int32);
}

IOperand	*Int32::operator+(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op + *this);
  long	value = (int)atoi(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int32(tmp));
}

IOperand	*Int32::operator-(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op - *this);
  long	value = (int)atoi(op.toString().c_str()) - this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int32(tmp));
}

IOperand	*Int32::operator*(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op * *this);
  long	value = (int)atoi(op.toString().c_str()) * this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int32(tmp));
}

IOperand	*Int32::operator/(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op / *this);
  long	value = (int)atoi(op.toString().c_str()) / this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int32(tmp));
}

IOperand	*Int32::operator%(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op % *this);
  long	value = (int)atoi(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Int32(tmp));
}
