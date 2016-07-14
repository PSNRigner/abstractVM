//
// Float.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:27:07 2016 loic frasse-mathon
// Last update Thu Jul 14 10:44:57 2016 loic frasse-mathon
//

#ifndef FLOAT_HH_
# define FLOAT_HH_

# include "IOperand.hh"

class		AFloat : public IOperand
{
public:
  AFloat(const std::string &);
  virtual ~AFloat();
  virtual std::string	toString() const;
  virtual eOperandType	getType() const;
  virtual IOperand	*operator+(const IOperand &) const;
  virtual IOperand	*operator-(const IOperand &) const;
  virtual IOperand	*operator*(const IOperand &) const;
  virtual IOperand	*operator/(const IOperand &) const;
  virtual IOperand	*operator%(const IOperand &) const;

private:
  float			data;
};

#endif /* !FLOAT_HH_ */
