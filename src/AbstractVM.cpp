//
// AbstractVM.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 14:26:56 2016 loic frasse-mathon
<<<<<<< HEAD
// Last update Fri Jul 15 11:14:29 2016 adrien velly
// Last update Fri Jul 15 09:53:06 2016 Clément LECOMTE
// Last update Fri Jul 15 10:05:31 2016 Clément LECOMTE
=======
// Last update Fri Jul 15 11:04:52 2016 loic frasse-mathon
>>>>>>> e4db22367e0aefe4b8ca67e0db5800ac26b92284
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
  int			i = 0;

  while (i != 16)
    {
      this->registry[i] = NULL;
      i++;
    }
  this->tab_str.push_back("Int8");
  this->tab_str.push_back("Int16");
  this->tab_str.push_back("Int32");
  this->tab_str.push_back("Float");
  this->tab_str.push_back("Double");
  this->tab_str.push_back("Bigdecimal");
  
  registerInstructions();
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
  std::string	tmp;

  t = 0;
  tmp = o.getType();
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
  while ((tmp != this->tab_str[t]) && (t < this->tab_str.size()))
    t++;
  if (t < this->tab_str.size())
    this->stack.push_front(Factory::createOperand((eOperandType)t, o.getValue()));
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
  size_t	i = 0;

  while (i != this->stack.size())
    {
      delete(this->stack.front());
      i++;
    }
  this->stack.erase(this->stack.begin(), this->stack.end());
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
  if (this->stack.size() < 1)
    throw new EmptyStackException;
  (void)o;
}

void	AbstractVM::add(const Cmd &command)
{
  if (this->stack.size() < 2)
    throw new EmptyStackException;
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
    throw new EmptyStackException;
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
    throw new EmptyStackException;
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
    throw new EmptyStackException;
  IOperand *tmp1 = stack.front();
  stack.pop_front();
  if (tmp1 == 0)
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
    throw new EmptyStackException;
  IOperand *tmp1 = stack.front();
  stack.pop_front();
  if (tmp1 == 0)
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
  (void)o;
}

void	AbstractVM::store(const Cmd &o)
{
  (void)o;
  int	i;

  const char * c = o.getV().c_str();
  i = atoi(c);
  this->registry[i] = this->stack.front();
}

void	AbstractVM::print(const Cmd &o)
{
  if (this->stack.size() < 1)
    throw new EmptyStackException;
  IOperand *tmp1 = stack.front();
  if (tmp1->getType() != Int8)
    throw new AssertException;
  tmp1->toString();
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
  size_t	t;
  std::string	tmp;

  t = 0;
  tmp = o.getCommand();
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
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
