//
// Int8.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:27:07 2016 loic frasse-mathon
// Last update Fri Jul 15 11:15:33 2016 loic frasse-mathon
//

#ifndef INT8_HH_
# define INT8_HH_

# include "IOperand.hh"

class		Int8 : public IOperand
{
public:
  Int8(const std::string &);
  virtual ~Int8();
  virtual std::string			toString() const;
  virtual eOperandType::eOperandType	getType() const;
  virtual IOperand			*operator+(const IOperand &) const;
  virtual IOperand			*operator-(const IOperand &) const;
  virtual IOperand			*operator*(const IOperand &) const;
  virtual IOperand			*operator/(const IOperand &) const;
  virtual IOperand			*operator%(const IOperand &) const;

private:
  char			data;
};

#endif /* !INT8_HH_ */
