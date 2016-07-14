//
// main.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 15:08:44 2016 loic frasse-mathon
// Last update Thu Jul 14 15:33:16 2016 loic frasse-mathon
//

#include "AbstractVM.hh"
#include "Parsing.hh"

int				main()
{
  AbstractVM			vm;
  Parsing			pars;
  std::vector<Cmd>		list;
  size_t			i;

  i = 0;
  list = pars.getList_obj();
  while (i != list.size())
    {
      vm.performCommand(list[i]);
      i++;
    }
  return (0);
}
