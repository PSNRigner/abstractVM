//
// AbstractVM.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 09:39:45 2016 loic frasse-mathon
// Last update Mon Jul 18 14:59:17 2016 loic frasse-mathon
//

#ifndef ABSTRACTVM_HH_
# define ABSTRACTVM_HH_

class		AbstractVM;
class		Instruction;

# include <list>
# include <vector>
# include <string>
# include "IOperand.hh"
# include "Factory.hh"
# include "Cmd.hh"
# include "Exceptions.hh"

# define REG_SIZE	16

class		Instruction
{
public:
  Instruction(const std::string &, void (AbstractVM::*)(const Cmd &));
  ~Instruction();
  const std::string	&getName() const;
  void			(AbstractVM::*&getFunction())(const Cmd &);
private:
  std::string		name;
  void			(AbstractVM::*func)(const Cmd &);
};

class		AbstractVM
{
public:
  AbstractVM();
  ~AbstractVM();
  void		performCommand(const Cmd &);

private:
  void		registerInstructions();
  void		push(const Cmd &);
  void		pop(const Cmd &);
  void		dump(const Cmd &);
  void		clear(const Cmd &);
  void		dup(const Cmd &);
  void		swap(const Cmd &);
  void		assert(const Cmd &);
  void		add(const Cmd &);
  void		sub(const Cmd &);
  void		mul(const Cmd &);
  void		div(const Cmd &);
  void		mod(const Cmd &);
  void		load(const Cmd &);
  void		store(const Cmd &);
  void		print(const Cmd &);
  void		exit(const Cmd &);

private:
  std::vector<Instruction *>	instructions;
  std::list<IOperand *>		stack;
  IOperand			*registry[REG_SIZE];
  std::vector<std::string>	tab_str;
};

bool            checkFloat(const std::string &o);
bool            checkInt(const std::string &o);

#endif /* !ABSTRACTVM_HH_ */
