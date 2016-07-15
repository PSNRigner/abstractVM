//
// main.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 15:08:44 2016 loic frasse-mathon
// Last update Fri Jul 15 10:15:23 2016 loic frasse-mathon
//

#include "AbstractVM.hh"
#include "Parsing.hh"
#include "Exceptions.hh"

int				usage(char **av)
{
  std::cout << "USAGE" << std::endl;
  std::cout << "\t" << av[0] << " [file]" << std::endl;
  std::cout << std::endl << "DESCRIPTION" << std::endl;
  std::cout << "\tfile : Optional specification of file to read." << std::endl;
  return (84);
}

void				parse(AbstractVM &vm)
{
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
}

void				parseFile(AbstractVM &vm, const std::string &path)
{
  Parsing			pars(path);
  std::vector<Cmd>		list;
  size_t			i;

  i = 0;
  list = pars.getList_obj();
  while (i != list.size())
    {
      vm.performCommand(list[i]);
      i++;
    }
}

int				main(int ac, char **av)
{
  AbstractVM			vm;

  try
    {
      if (ac == 1)
	parse(vm);
      else if (ac > 2 || std::string(av[1]) == "-h")
	return (usage(av));
      else
	parseFile(vm, av[1]);
    }
  catch (std::exception *ex)
    {
      std::cerr << ex->what() << std::endl;
      return (84);
    }
  return (0);
}
