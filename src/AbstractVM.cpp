//
// AbstractVM.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 14:26:56 2016 loic frasse-mathon
// Last update Thu Jul 14 17:12:39 2016 loic frasse-mathon
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
  instructions.push_back(new Instruction("pop", &AbstractVM::pop));
  instructions.push_back(new Instruction("dump", &AbstractVM::dump));
  instructions.push_back(new Instruction("clear", &AbstractVM::clear));
  instructions.push_back(new Instruction("dup", &AbstractVM::dup));
  instructions.push_back(new Instruction("swap", &AbstractVM::swap));
  instructions.push_back(new Instruction("assert", &AbstractVM::assert));
  instructions.push_back(new Instruction("add", &AbstractVM::add));
  instructions.push_back(new Instruction("sub", &AbstractVM::sub));
  instructions.push_back(new Instruction("mul", &AbstractVM::mul));
  instructions.push_back(new Instruction("div", &AbstractVM::div));
  instructions.push_back(new Instruction("mod", &AbstractVM::mod));
  instructions.push_back(new Instruction("load", &AbstractVM::load));
  instructions.push_back(new Instruction("store", &AbstractVM::store));
  instructions.push_back(new Instruction("print", &AbstractVM::print));
  instructions.push_back(new Instruction("exit", &AbstractVM::exit));
}

void	AbstractVM::push(const Cmd &o)
{
  size_t	t;

  t = 0;
  while ((o.getType() != this->tab_str[t]) && (t < this->tab_str.size()))
    t++;
  if (t - 1 < this->tab_str.size())
    this->stack.push_front(Factory::createOperand((eOperandType)t, o.getValue()));
  else
    throw new SyntaxException;
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
  ::exit(0);
}

void	AbstractVM::performCommand(const Cmd &o)
{
  (void)o;
}
