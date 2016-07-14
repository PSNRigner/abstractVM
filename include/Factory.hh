//
// Factory.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 09:08:37 2016 loic frasse-mathon
// Last update Thu Jul 14 09:56:53 2016 loic frasse-mathon
//

#ifndef FACTORY_HH_
# define FACTORY_HH_

# include <string>
# include "IOperand.hh"

enum		eOperandType
  {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal
  };

class		Factory
{
public:
  static IOperand	*createOperand(eOperandType, const std::string &);
private:
  IOperand		*createInt8(const std::string &);
  IOperand		*createInt16(const std::string &);
  IOperand		*createInt32(const std::string &);
  IOperand		*createFloat(const std::string &);
  IOperand		*createDouble(const std::string &);
  IOperand		*createBigDecimal(const std::string &);
};

#endif /* !FACTORY_HH_ */
