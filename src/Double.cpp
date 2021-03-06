//
// Double.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:51:03 2016 loic frasse-mathon
// Last update Mon Jul 18 15:01:20 2016 loic frasse-mathon
//

#include <cstdlib>
#include <sstream>
#include <cfloat>
#include <cmath>
#include "Double.hh"
#include "Exceptions.hh"

Double::Double(const std::string &string)
{
  if (!checkFloat(string))
    throw new SyntaxException;
  __float128	n = atof(string.c_str());
  if (n > DBL_MAX)
    throw new OverflowException;
  if (n < DBL_MIN)
    throw new UnderflowException;
  this->data = (double)n;
}

Double::~Double()
{
}

std::string		Double::toString() const
{
  std::ostringstream	oss;
  std::string		tmp;

  oss << data;
  tmp = oss.str();
  return (tmp);
}

eOperandType::eOperandType	Double::getType() const
{
  return (eOperandType::Double);
}

IOperand	*Double::operator+(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op + *this);
  double	value = (double)atof(op.toString().c_str()) + this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Double(tmp));
}

IOperand	*Double::operator-(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op - *this);
  double	value = this->data - (double)atof(op.toString().c_str());
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Double(tmp));
}

IOperand	*Double::operator*(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op * *this);
  double	value = (double)atof(op.toString().c_str()) * this->data;
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Double(tmp));
}

IOperand	*Double::operator/(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op / *this);
  double	value = this->data / (double)atof(op.toString().c_str());
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Double(tmp));
}

IOperand	*Double::operator%(const IOperand &op) const
{
  if (op.getType() > this->getType())
    return (op % *this);
  double	value = fmod(this->data, atof(op.toString().c_str()));
  std::ostringstream	oss;
  std::string		tmp;

  oss << value;
  tmp = oss.str();
  return (new Double(tmp));
}
