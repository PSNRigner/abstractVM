//
// main.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 15:08:44 2016 loic frasse-mathon
// Last update Thu Jul 14 15:14:34 2016 loic frasse-mathon
//

#include "Parsing.hh"

int				main()
{
  Parsing			pars;
  std::vector<Cmd>		list;
  std::vector<std::string>	l_s;
  size_t			i;

  l_s = pars.getList_cmd();
  while (i != l_s.size())
    {
      std::cout << l_s[i] << std::endl;
      i++;
    }
  i = 0;
  list = pars.getList_obj();
  while (i != list.size())
    {
      std::cout << list[i].getCommand() << std::endl;
      i++;
    }
}
