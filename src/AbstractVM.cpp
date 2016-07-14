//
// AbstractVM.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 14:26:56 2016 loic frasse-mathon
// Last update Thu Jul 14 16:37:42 2016 Clément LECOMTE
//

#include "AbstractVM.hh"

Instruction::Instruction(const std::string &name, void (AbstractVM::*func)(const Cmd &))
  : name(name), func(func)
{
}

Instruction::~Instruction()
{
}

const std::string	&Instruction::getName() const
{
  return (name);
}

void	(AbstractVM::*&Instruction::getFunction())(const Cmd &)
{
  return (func);
}

AbstractVM::AbstractVM()
{
  this->tab_str.push_back("Int8");
  this->tab_str.push_back("Int16");
  this->tab_str.push_back("Int32");
  this->tab_str.push_back("Float");
  this->tab_str.push_back("Double");
  this->tab_str.push_back("BigDecimal");
}

AbstractVM::~AbstractVM()
{
}

void	AbstractVM::registerInstructions()
{
  instructions.push_back(new Instruction("push", &AbstractVM::push));
}

void	AbstractVM::push(const Cmd &o)
{
  
  (void)o;
}

void	AbstractVM::pop(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::dump(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::clear(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::dup(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::swap(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::assert(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::add(const Cmd &command)
{
  (void)command;
}

void	AbstractVM::sub(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::mul(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::div(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::mod(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::load(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::store(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::print(const Cmd &o)
{
  (void)o;
}

void	AbstractVM::exit(const Cmd &o)
{
  //TODO FREE ALL
  (void)o;
  exit(0);
}
