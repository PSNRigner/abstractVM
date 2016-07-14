//
// Double.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:51:03 2016 loic frasse-mathon
// Last update Thu Jul 14 11:32:16 2016 loic frasse-mathon
//

#include <cstdlib>
#include <sstream>
#include <cfloat>
#include "Double.hh"
#include "Exceptions.hh"

ADouble::ADouble(const std::string &string)
{
  __float128	n = atof(string.c_str());
  if (n > DBL_MAX)
    throw new OverflowException;
  if (n < DBL_MIN)
    throw new UnderflowException;
  this->data = (char)n;
}

ADouble::~ADouble()
{
}

std::string		ADouble::toString() const
{
  std::ostringstream	oss;
  std::string		tmp;

  oss << (int)data;
  tmp = oss.str();
  return (tmp);
}

eOperandType	ADouble::getType() const
{
  return (Double);
}

IOperand	*ADouble::operator+(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op + *this);
  double	value = (double)atof(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new ADouble(tmp));
}

IOperand	*ADouble::operator-(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op - *this);
  double	value = (double)atof(op.toString().c_str()) - this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new ADouble(tmp));
}

IOperand	*ADouble::operator*(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op * *this);
  double	value = (double)atof(op.toString().c_str()) * this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new ADouble(tmp));
}

IOperand	*ADouble::operator/(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op / *this);
  double	value = (double)atof(op.toString().c_str()) / this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new ADouble(tmp));
}

IOperand	*ADouble::operator%(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op % *this);
  double	value = (double)atof(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new ADouble(tmp));
}
