//
// BigDecimal.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 11:32:42 2016 loic frasse-mathon
// Last update Fri Jul 15 11:20:36 2016 loic frasse-mathon
//

#include "BigDecimal.hh"

BigDecimal::BigDecimal(const std::string &value)
{
  this->data = value;
}

BigDecimal::~BigDecimal()
{
}

IOperand	*BigDecimal::operator+(const IOperand &op) const
{
  (void)op;
  return (NULL);
  /* TODO */
}

IOperand	*BigDecimal::operator-(const IOperand &op) const
{
  (void)op;
  return (NULL);
  /* TODO */
}

IOperand	*BigDecimal::operator*(const IOperand &op) const
{
  (void)op;
  return (NULL);
  /* TODO */
}

IOperand	*BigDecimal::operator/(const IOperand &op) const
{
  (void)op;
  return (NULL);
  /* TODO */
}

IOperand	*BigDecimal::operator%(const IOperand &op) const
{
  (void)op;
  return (NULL);
  /* TODO */
}

eOperandType::eOperandType	BigDecimal::getType() const
{
  return (eOperandType::BigDecimal);
}

std::string	BigDecimal::toString() const
{
  return (this->data);
}
