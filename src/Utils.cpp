//
// test.cpp for header in /home/lecomt_e/abstractVM/src
// 
// Made by Clément LECOMTE
// Login   <lecomt_e@epitech.net>
// 
// Started on  Sat Jul 16 11:56:38 2016 Clément LECOMTE
// Last update Mon Jul 18 15:04:46 2016 loic frasse-mathon
//

#include	"AbstractVM.hh"

bool		checkFloat(const std::string &o)
{
  size_t	i;
  bool		j;

  i = 0;
  j = false;
  if (o.empty())
    return (false);
  if (o[0] == '-' && o.size() > 1)
    i++;
  while (i < o.size())
    {
      if ((o[i] >= '0') && (o[i] <= '9'))
	i++;
      else if (i != 0 && o[i] == '.' && i + 1 < o.size())
	{
	  i++;
	  if (j)
	    return (false);
	  j = true;
	}
      else
	return (false);
    }
  return (true);
}


bool		checkInt(const std::string &o)
{
  size_t	i;

  i = 0;
  if (o.empty())
    return (false);
  if (o[0] == '-' && o.size() > 1)
    i++;
  while (i < o.size())
    {
      if ((o[i] >= '0') && (o[i] <= '9'))
	i++;
      else
	return (false);
    }
  return (true);
}
