//
// Float.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:51:03 2016 loic frasse-mathon
// Last update Sun Jul 17 13:36:47 2016 loic frasse-mathon
//

#include <cstdlib>
#include <sstream>
#include <cfloat>
#include <cmath>
#include "Float.hh"
#include "Exceptions.hh"

Float::Float(const std::string &string)
{
  __float128	n = atof(string.c_str());
  if (n > FLT_MAX)
    throw new OverflowException;
  if (n < FLT_MIN)
    throw new UnderflowException;
  this->data = (float)n;
}

Float::~Float()
{
}

std::string		Float::toString() const
{
  std::ostringstream	oss;
  std::string		tmp;

  oss << data;
  tmp = oss.str();
  return (tmp);
}

eOperandType::eOperandType	Float::getType() const
{
  return (eOperandType::Float);
}

IOperand	*Float::operator+(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op + *this);
  double	value = (float)atof(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Float(tmp));
}

IOperand	*Float::operator-(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op - *this);
  double	value = this->data - (float)atof(op.toString().c_str());
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Float(tmp));
}

IOperand	*Float::operator*(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op * *this);
  double	value = (float)atof(op.toString().c_str()) * this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Float(tmp));
}

IOperand	*Float::operator/(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op / *this);
  double	value = this->data / (float)atof(op.toString().c_str());
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Float(tmp));
}

IOperand	*Float::operator%(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op % *this);
  double	value = fmodf(this->data, atof(op.toString().c_str()));
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Float(tmp));
}
