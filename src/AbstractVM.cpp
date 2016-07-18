//
// AbstractVM.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 14:26:56 2016 loic frasse-mathon
// Last update Mon Jul 18 11:12:57 2016 loic frasse-mathon
//

#include <algorithm>
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
  size_t		i = 0;

  while (i < REG_SIZE)
    {
      this->registry[i] = NULL;
      i++;
    }
  this->tab_str.push_back("int8");
  this->tab_str.push_back("int16");
  this->tab_str.push_back("int32");
  this->tab_str.push_back("float");
  this->tab_str.push_back("double");
  this->tab_str.push_back("bigdecimal");
  this->registerInstructions();
}

AbstractVM::~AbstractVM()
{
  size_t	i;

  i = 0;
  this->tab_str.erase(this->tab_str.begin(), this->tab_str.end());
  while (i < REG_SIZE)
    {
      if (this->registry[i] != NULL)
	delete this->registry[i];
      i++;
    }
  while (!this->stack.empty())
    {
      delete this->stack.front();
      this->stack.erase(this->stack.begin());
    }
  while (!this->instructions.empty())
    {
      delete this->instructions.front();
      this->instructions.erase(this->instructions.begin());
    }
}

void	AbstractVM::registerInstructions()
{
  this->instructions.push_back(new Instruction("push", &AbstractVM::push));
  this->instructions.push_back(new Instruction("pop", &AbstractVM::pop));
  this->instructions.push_back(new Instruction("dump", &AbstractVM::dump));
  this->instructions.push_back(new Instruction("clear", &AbstractVM::clear));
  this->instructions.push_back(new Instruction("dup", &AbstractVM::dup));
  this->instructions.push_back(new Instruction("swap", &AbstractVM::swap));
  this->instructions.push_back(new Instruction("assert", &AbstractVM::assert));
  this->instructions.push_back(new Instruction("add", &AbstractVM::add));
  this->instructions.push_back(new Instruction("sub", &AbstractVM::sub));
  this->instructions.push_back(new Instruction("mul", &AbstractVM::mul));
  this->instructions.push_back(new Instruction("div", &AbstractVM::div));
  this->instructions.push_back(new Instruction("mod", &AbstractVM::mod));
  this->instructions.push_back(new Instruction("load", &AbstractVM::load));
  this->instructions.push_back(new Instruction("store", &AbstractVM::store));
  this->instructions.push_back(new Instruction("print", &AbstractVM::print));
  this->instructions.push_back(new Instruction("exit", &AbstractVM::exit));
}

void	AbstractVM::push(const Cmd &o)
{
  size_t	t;
  std::string	tmp;

  t = 0;
  tmp = o.getType();
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
  while ((tmp != this->tab_str[t]) && (t < this->tab_str.size()))
    t++;
  if (t < this->tab_str.size())
    this->stack.push_front(Factory::createOperand((eOperandType::eOperandType)t, o.getValue()));
  else
    throw new SyntaxException;
}

void	AbstractVM::pop(const Cmd &o)
{
  (void)o;
  if (this->stack.size() == 0)
    throw new EmptyStackException;
  else
    {
      delete stack.front();
      this->stack.erase(this->stack.begin());
    }
}

void	AbstractVM::dump(const Cmd &o)
{
  (void)o;
  std::list<IOperand *>::iterator	it = stack.begin();
  std::list<IOperand *>::iterator	it_end = stack.end();
  while (it != it_end)
    {
      std::cout << (*it)->toString() << std::endl;
      it++;
    }
}

void	AbstractVM::clear(const Cmd &o)
{
  (void)o;
  while (!this->stack.empty())
    {
      delete(this->stack.front());
      this->stack.erase(this->stack.begin());
    }
}

void	AbstractVM::dup(const Cmd &o)
{
  (void)o;
  if (this->stack.size() != 0)
    this->stack.push_front(Factory::createOperand(this->stack.front()->getType(), this->stack.front()->toString()));
  else
    throw new EmptyStackException;
}

void	AbstractVM::swap(const Cmd &o)
{
  if (this->stack.size() < 2)
    throw new EmptyStackException;
  IOperand *tmp1 = stack.front();
  stack.pop_front();
  IOperand *tmp2 = stack.front();
  stack.pop_front();
  stack.push_front(tmp1);
  stack.push_front(tmp2);
  (void)o;
}

void	AbstractVM::assert(const Cmd &o)
{
  size_t	t;
  std::string	tmp;
  if (this->stack.size() < 1)
    throw new EmptyStackException; 
  IOperand *tmp1 = stack.front();
  IOperand *tmp2;

  t = 0;
  tmp = o.getType();
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
  while ((tmp != this->tab_str[t]) && (t < this->tab_str.size()))
    t++;
  if (t < this->tab_str.size())
    tmp2 = Factory::createOperand((eOperandType::eOperandType)t, o.getValue());
  else
    throw new SyntaxException;
  if (tmp1->toString() != tmp2->toString())
    throw new AssertException;
}

void	AbstractVM::add(const Cmd &command)
{
  if (this->stack.size() < 2)
    throw new StackOperandException;
  IOperand *tmp1 = stack.front();
  stack.pop_front();
  IOperand *tmp2 = stack.front();
  stack.pop_front();
  IOperand *tmp3;
  tmp3 = *tmp1 + *tmp2;
  stack.push_front(tmp3);
  delete tmp1;
  delete tmp2;
  (void)command;
}

void	AbstractVM::sub(const Cmd &o)
{
  if (this->stack.size() < 2)
    throw new StackOperandException;
  IOperand *tmp1 = stack.front();
  stack.pop_front();
  IOperand *tmp2 = stack.front();
  stack.pop_front();
  IOperand *tmp3;
  tmp3 = *tmp2 - *tmp1;
  stack.push_front(tmp3);
  delete tmp1;
  delete tmp2;
  (void)o;
}

void	AbstractVM::mul(const Cmd &o)
{
  if (this->stack.size() < 2)
    throw new StackOperandException;
  IOperand *tmp1 = stack.front();
  stack.pop_front();
  IOperand *tmp2 = stack.front();
  stack.pop_front();
  IOperand *tmp3;
  tmp3 = *tmp2 * *tmp1;
  stack.push_front(tmp3);
  delete tmp1;
  delete tmp2;
  (void)o;
}

void	AbstractVM::div(const Cmd &o)
{
 if (this->stack.size() < 2)
    throw new StackOperandException;
  IOperand *tmp1 = stack.front();
  stack.pop_front();
  if (tmp1->toString() == "0")
    throw new DivByZeroException;
  IOperand *tmp2 = stack.front();
  stack.pop_front();
  IOperand *tmp3;
  tmp3 = *tmp2 / *tmp1;
  stack.push_front(tmp3);
  delete tmp1;
  delete tmp2;
  (void)o;
}

void	AbstractVM::mod(const Cmd &o)
{
  if (this->stack.size() < 2)
    throw new StackOperandException;
  IOperand *tmp1 = stack.front();
  stack.pop_front();
  if (tmp1->toString() == "0")
    throw new DivByZeroException;
  IOperand *tmp2 = stack.front();
  stack.pop_front();
  IOperand *tmp3;
  tmp3 = *tmp2 % *tmp1;
  stack.push_front(tmp3);
  delete tmp1;
  delete tmp2;
  (void)o;
}

void	AbstractVM::load(const Cmd &o)
{
  int	i;

  const char * c = o.getV().c_str();
  i = atoi(c);
  if (i < 0 || i >= REG_SIZE)
    throw new SyntaxException;
  if (this->registry[i] == NULL)
    throw new EmptyRegistryException;
  else
    this->stack.push_back(Factory::createOperand(this->registry[i]->getType(), this->registry[i]->toString()));
}

void	AbstractVM::store(const Cmd &o)
{
  int	i;

  if (this->stack.size() < 1)
    throw new EmptyStackException;
  const char * c = o.getV().c_str();
  i = atoi(c);
  if (i < 0 || i >= REG_SIZE)
    throw new SyntaxException;
  if (this->registry[i] != NULL)
    delete this->registry[i];
  this->registry[i] = Factory::createOperand(this->stack.front()->getType(), this->stack.front()->toString());
  this->stack.pop_front();
}

void	AbstractVM::print(const Cmd &o)
{
  if (this->stack.size() < 1)
    throw new EmptyStackException;
  IOperand *tmp1 = stack.front();
  if (tmp1->getType() != eOperandType::Int8)
    throw new AssertException;
  char c = (char)atoi(tmp1->toString().c_str());
  std::cout << c << std::endl;
  (void)o;
}

void	AbstractVM::exit(const Cmd &o)
{
  /* TODO FREE ALL */
  (void)o;
  ::exit(0);
}

void		AbstractVM::performCommand(const Cmd &o)
{
  size_t	t;
  std::string	tmp;

  t = 0;
  tmp = o.getCommand();
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
  if (tmp.find(';') != std::string::npos)
    tmp = tmp.substr(0, tmp.find(';'));
  if (tmp.empty())
    return ;
  while (t < instructions.size())
    {
      if (instructions[t]->getName() == tmp)
	{
	  (this->*(instructions[t]->getFunction()))(o);
	  return ;
	}
      t++;
    }
  throw new SyntaxException;
}
