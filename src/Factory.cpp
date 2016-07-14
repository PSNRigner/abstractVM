//
// Factory.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:06:04 2016 loic frasse-mathon
// Last update Thu Jul 14 10:46:29 2016 loic frasse-mathon
//

#include "Factory.hh"
#include "Int8.hh"
#include "Int16.hh"
#include "Int32.hh"
#include "Float.hh"
#include "Double.hh"
#include "BigDecimal.hh"

Factory	Factory::instance;

Factory::Factory()
{
  this->methods.push_back(&Factory::createInt8);
  this->methods.push_back(&Factory::createInt16);
  this->methods.push_back(&Factory::createInt32);
  this->methods.push_back(&Factory::createFloat);
  this->methods.push_back(&Factory::createDouble);
  this->methods.push_back(&Factory::createBigDecimal);
}

Factory::~Factory()
{
}

IOperand	*Factory::createOperand(eOperandType type, const std::string &value)
{
  Factory	&factory = Factory::instance;
  if (type < 0 || type >= factory.methods.size())
    return (NULL);
  return ((factory.*(factory.methods[type]))(value));
}

IOperand	*Factory::createInt8(const std::string &value)
{
  return (new AInt8(value));
}

IOperand	*Factory::createInt16(const std::string &value)
{
  return (new AInt16(value));
}

IOperand	*Factory::createInt32(const std::string &value)
{
  return (new AInt32(value));
}

IOperand	*Factory::createFloat(const std::string &value)
{
  return (new AFloat(value));
}

IOperand	*Factory::createDouble(const std::string &value)
{
  return (new ADouble(value));
}

IOperand	*Factory::createBigDecimal(const std::string &value)
{
  return (new ABigDecimal(value));
}
