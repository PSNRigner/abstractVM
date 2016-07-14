//
// Int32.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:27:07 2016 loic frasse-mathon
// Last update Thu Jul 14 10:44:17 2016 loic frasse-mathon
//

#ifndef INT32_HH_
# define INT32_HH_

# include "IOperand.hh"

class		AInt32 : public IOperand
{
public:
  AInt32(const std::string &);
  virtual ~AInt32();
  virtual std::string	toString() const;
  virtual eOperandType	getType() const;
  virtual IOperand	*operator+(const IOperand &) const;
  virtual IOperand	*operator-(const IOperand &) const;
  virtual IOperand	*operator*(const IOperand &) const;
  virtual IOperand	*operator/(const IOperand &) const;
  virtual IOperand	*operator%(const IOperand &) const;

private:
  int			data;
};

#endif /* !INT32_HH_ */
