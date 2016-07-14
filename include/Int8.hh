//
// Int8.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:27:07 2016 loic frasse-mathon
// Last update Thu Jul 14 10:54:30 2016 loic frasse-mathon
//

#ifndef INT8_HH_
# define INT8_HH_

# include "IOperand.hh"

class		AInt8 : public IOperand
{
public:
  AInt8(const std::string &);
  virtual ~AInt8();
  virtual std::string	toString() const;
  virtual eOperandType	getType() const;
  virtual IOperand	*operator+(const IOperand &) const;
  virtual IOperand	*operator-(const IOperand &) const;
  virtual IOperand	*operator*(const IOperand &) const;
  virtual IOperand	*operator/(const IOperand &) const;
  virtual IOperand	*operator%(const IOperand &) const;

private:
  char			data;
};

#endif /* !INT8_HH_ */
