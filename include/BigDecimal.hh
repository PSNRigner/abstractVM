//
// BigDecimal.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:27:07 2016 loic frasse-mathon
// Last update Thu Jul 14 10:46:58 2016 loic frasse-mathon
//

#ifndef BIGDECIMAL_HH_
# define BIGDECIMAL_HH_

# include "IOperand.hh"

class		ABigDecimal : public IOperand
{
public:
  ABigDecimal(const std::string &);
  virtual ~ABigDecimal();
  virtual std::string	toString() const;
  virtual eOperandType	getType() const;
  virtual IOperand	*operator+(const IOperand &) const;
  virtual IOperand	*operator-(const IOperand &) const;
  virtual IOperand	*operator*(const IOperand &) const;
  virtual IOperand	*operator/(const IOperand &) const;
  virtual IOperand	*operator%(const IOperand &) const;

private:
  std::string		data;
};

#endif /* !BIGDECIMAL_HH_ */
