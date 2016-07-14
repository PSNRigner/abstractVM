//
// Double.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:27:07 2016 loic frasse-mathon
// Last update Thu Jul 14 10:44:31 2016 loic frasse-mathon
//

#ifndef DOUBLE_HH_
# define DOUBLE_HH_

# include "IOperand.hh"

class		ADouble : public IOperand
{
public:
  ADouble(const std::string &);
  virtual ~ADouble();
  virtual std::string	toString() const;
  virtual eOperandType	getType() const;
  virtual IOperand	*operator+(const IOperand &) const;
  virtual IOperand	*operator-(const IOperand &) const;
  virtual IOperand	*operator*(const IOperand &) const;
  virtual IOperand	*operator/(const IOperand &) const;
  virtual IOperand	*operator%(const IOperand &) const;

private:
  double		data;
};

#endif /* !DOUBLE_HH_ */
