//
// Factory.hh for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 09:08:37 2016 loic frasse-mathon
// Last update Fri Jul 15 11:17:58 2016 loic frasse-mathon
//

#ifndef FACTORY_HH_
# define FACTORY_HH_

namespace	eOperandType
{
  enum		eOperandType
  {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal
  };
}

# include <string>
# include <vector>
# include "IOperand.hh"

class		Factory
{
public:
  static IOperand	*createOperand(eOperandType::eOperandType, const std::string &);
private:
  Factory();
  ~Factory();
  IOperand		*createInt8(const std::string &);
  IOperand		*createInt16(const std::string &);
  IOperand		*createInt32(const std::string &);
  IOperand		*createFloat(const std::string &);
  IOperand		*createDouble(const std::string &);
  IOperand		*createBigDecimal(const std::string &);

  static Factory						instance;
  std::vector<IOperand *(Factory::*)(const std::string &)>	methods;
};

#endif /* !FACTORY_HH_ */
