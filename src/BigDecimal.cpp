//
// BigDecimal.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 11:32:42 2016 loic frasse-mathon
// Last update Fri Jul 15 14:27:59 2016 loic frasse-mathon
//

#include "BigDecimal.hh"
#include "Exceptions.hh"

BigDecimal::BigDecimal(const std::string &value)
{
  this->data = value;
}

BigDecimal::~BigDecimal()
{
}

IOperand	*BigDecimal::operator+(const IOperand &op) const
{
  std::string	tmp1;
  std::string	tmp2;

  tmp1 = this->data;
  tmp2 = op.toString();
  throw new NotYetSupportedException;
  /* TODO */
}

IOperand	*BigDecimal::operator-(const IOperand &op) const
{
  (void)op;
  throw new NotYetSupportedException;
  /* TODO */
}

IOperand	*BigDecimal::operator*(const IOperand &op) const
{
  (void)op;
  throw new NotYetSupportedException;
  /* TODO */
}

IOperand	*BigDecimal::operator/(const IOperand &op) const
{
  (void)op;
  throw new NotYetSupportedException;
  /* TODO */
}

IOperand	*BigDecimal::operator%(const IOperand &op) const
{
  (void)op;
  throw new NotYetSupportedException;
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
