//
// BigDecimal.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:27:07 2016 loic frasse-mathon
// Last update Fri Jul 15 11:14:19 2016 loic frasse-mathon
//

#ifndef BIGDECIMAL_HH_
# define BIGDECIMAL_HH_

# include "IOperand.hh"

class		BigDecimal : public IOperand
{
public:
  BigDecimal(const std::string &);
  virtual ~BigDecimal();
  virtual std::string			toString() const;
  virtual eOperandType::eOperandType	getType() const;
  virtual IOperand			*operator+(const IOperand &) const;
  virtual IOperand			*operator-(const IOperand &) const;
  virtual IOperand			*operator*(const IOperand &) const;
  virtual IOperand			*operator/(const IOperand &) const;
  virtual IOperand			*operator%(const IOperand &) const;

private:
  std::string		data;
};

#endif /* !BIGDECIMAL_HH_ */
