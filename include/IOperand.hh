//
// IOperand.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 09:05:15 2016 loic frasse-mathon
// Last update Thu Jul 14 09:57:30 2016 loic frasse-mathon
//

#ifndef IOPERAND_HH_
# define IOPERAND_HH_

class		IOperand;

# include <string>
# include "Factory.hh"

class		IOperand
{
public:
  virtual std::string		toString() const = 0;
  virtual eOperandType		getType() const = 0;
  virtual IOperand		*operator+(const IOperand &) const = 0;
  virtual IOperand		*operator-(const IOperand &) const = 0;
  virtual IOperand		*operator*(const IOperand &) const = 0;
  virtual IOperand		*operator/(const IOperand &) const = 0;
  virtual IOperand		*operator%(const IOperand &) const = 0;

  virtual ~IOperand() {}
};

#endif /* !IOPERAND_HH_ */
