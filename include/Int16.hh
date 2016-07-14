//
// Int16.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:27:07 2016 loic frasse-mathon
// Last update Thu Jul 14 10:45:08 2016 loic frasse-mathon
//

#ifndef INT16_HH_
# define INT16_HH_

# include "IOperand.hh"

class		AInt16 : public IOperand
{
public:
  AInt16(const std::string &);
  virtual ~AInt16();
  virtual std::string	toString() const;
  virtual eOperandType	getType() const;
  virtual IOperand	*operator+(const IOperand &) const;
  virtual IOperand	*operator-(const IOperand &) const;
  virtual IOperand	*operator*(const IOperand &) const;
  virtual IOperand	*operator/(const IOperand &) const;
  virtual IOperand	*operator%(const IOperand &) const;

private:
  short			data;
};

#endif /* !INT16_HH_ */
