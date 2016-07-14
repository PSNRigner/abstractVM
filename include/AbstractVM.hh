//
// AbstractVM.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 09:39:45 2016 loic frasse-mathon
// Last update Thu Jul 14 10:04:18 2016 loic frasse-mathon
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

class		Instruction
{
public:
  Instruction(const std::string &, void (AbstractVM::*)(const std::vector<std::string> &));
  ~Instruction();
  const std::string	&getName() const;
  void			(AbstractVM::*&getFunction())(const std::vector<std::string> &);
private:
  std::string		name;
  void			(AbstractVM::*func)(const std::vector<std::string> &);
};

class		AbstractVM
{
public:
  AbstractVM();
  ~AbstractVM();

private:
  void		registerInstructions();
  void		push(const std::vector<std::string> &);
  void		pop(const std::vector<std::string> &);
  void		dump(const std::vector<std::string> &);
  void		clear(const std::vector<std::string> &);
  void		dup(const std::vector<std::string> &);
  void		swap(const std::vector<std::string> &);
  void		assert(const std::vector<std::string> &);
  void		add(const std::vector<std::string> &);
  void		sub(const std::vector<std::string> &);
  void		mul(const std::vector<std::string> &);
  void		div(const std::vector<std::string> &);
  void		mod(const std::vector<std::string> &);
  void		load(const std::vector<std::string> &);
  void		store(const std::vector<std::string> &);
  void		print(const std::vector<std::string> &);
  void		exit(const std::vector<std::string> &);

private:
  std::list<Instruction *>	instructions;
  std::list<IOperand *>		stack;
  std::list<IOperand *>		registry;
};

#endif /* !ABSTRACTVM_HH_ */
