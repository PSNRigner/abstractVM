//
// Int16.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 10:27:07 2016 loic frasse-mathon
// Last update Fri Jul 15 11:16:12 2016 loic frasse-mathon
//

#ifndef INT16_HH_
# define INT16_HH_

# include "IOperand.hh"

class		Int16 : public IOperand
{
public:
  Int16(const std::string &);
  virtual ~Int16();
  virtual std::string			toString() const;
  virtual eOperandType::eOperandType	getType() const;
  virtual IOperand			*operator+(const IOperand &) const;
  virtual IOperand			*operator-(const IOperand &) const;
  virtual IOperand			*operator*(const IOperand &) const;
  virtual IOperand			*operator/(const IOperand &) const;
  virtual IOperand			*operator%(const IOperand &) const;

private:
  short			data;
};

#endif /* !INT16_HH_ */
