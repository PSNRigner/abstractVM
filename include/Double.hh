//
// Double.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:27:07 2016 loic frasse-mathon
// Last update Fri Jul 15 11:17:05 2016 loic frasse-mathon
//

#ifndef DOUBLE_HH_
# define DOUBLE_HH_

# include "IOperand.hh"

class		Double : public IOperand
{
public:
  Double(const std::string &);
  virtual ~Double();
  virtual std::string			toString() const;
  virtual eOperandType::eOperandType	getType() const;
  virtual IOperand			*operator+(const IOperand &) const;
  virtual IOperand			*operator-(const IOperand &) const;
  virtual IOperand			*operator*(const IOperand &) const;
  virtual IOperand			*operator/(const IOperand &) const;
  virtual IOperand			*operator%(const IOperand &) const;

private:
  double		data;
};

#endif /* !DOUBLE_HH_ */
