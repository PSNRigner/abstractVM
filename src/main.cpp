//
// main.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 15:08:44 2016 loic frasse-mathon
// Last update Mon Jul 18 11:11:20 2016 loic frasse-mathon
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

void				parse(AbstractVM &vm, size_t &i)
{
  Parsing			pars;
  std::vector<Cmd>		list;

  list = pars.getList_obj();
  while (i != list.size())
    {
      vm.performCommand(list[i]);
      i++;
    }
  throw new NoExitException;
}

void				parseFile(AbstractVM &vm, const std::string &path, size_t &i)
{
  Parsing			pars(path);
  std::vector<Cmd>		list;

  list = pars.getList_obj();
  while (i != list.size())
    {
      vm.performCommand(list[i]);
      i++;
    }
  throw new NoExitException;
}

int				main(int ac, char **av)
{
  AbstractVM			vm;
  size_t			i;

  try
    {
      i = 0;
      if (ac == 1)
	parse(vm, i);
      else if (ac > 2 || std::string(av[1]) == "-h")
	return (usage(av));
      else
	parseFile(vm, av[1], i);
    }
  catch (VMException *ex)
    {
      std::cerr << "Line " << i + 1 << " : " << ex->what() << std::endl;
      return (84);
    }
  return (0);
}
