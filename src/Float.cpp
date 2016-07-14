//
// Float.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:51:03 2016 loic frasse-mathon
// Last update Thu Jul 14 23:14:51 2016 loic frasse-mathon
//

#include <cstdlib>
#include <sstream>
#include <cfloat>
#include "Float.hh"
#include "Exceptions.hh"

AFloat::AFloat(const std::string &string)
{
  __float128	n = atof(string.c_str());
  if (n > FLT_MAX)
    throw new OverflowException;
  if (n < FLT_MIN)
    throw new UnderflowException;
  this->data = (float)n;
}

AFloat::~AFloat()
{
}

std::string		AFloat::toString() const
{
  std::ostringstream	oss;
  std::string		tmp;

  oss << data;
  tmp = oss.str();
  return (tmp);
}

eOperandType	AFloat::getType() const
{
  return (Float);
}

IOperand	*AFloat::operator+(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op + *this);
  double	value = (float)atof(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AFloat(tmp));
}

IOperand	*AFloat::operator-(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op - *this);
  double	value = (float)atof(op.toString().c_str()) - this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AFloat(tmp));
}

IOperand	*AFloat::operator*(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op * *this);
  double	value = (float)atof(op.toString().c_str()) * this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AFloat(tmp));
}

IOperand	*AFloat::operator/(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op / *this);
  double	value = (float)atof(op.toString().c_str()) / this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AFloat(tmp));
}

IOperand	*AFloat::operator%(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op % *this);
  double	value = (float)atof(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new AFloat(tmp));
}
