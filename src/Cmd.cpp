//
// Cmd.cpp for  in /home/velly_a/VM
// 
// Made by adrien velly$
// Login   <velly_a@epitech.net>
// 
// Started on  14 Jul 14 10:28 AM 2016 adrien velly
// Last update Thu Jul 14 15:17:13 2016 loic frasse-mathon
//

#include "Cmd.hh"

Cmd::Cmd(const std::string &command)
{
  setCommand(command);
}

void     Cmd::setCommand(const std::string &value)
{
  this->command = value;
}

Cmd::~Cmd()
{
  this->command.erase();
}

std::string     Cmd::getCommand() const
{
  int		i = 0;
  std::string	tmp;

  while (this->command[i] != ' ' && this->command[i] != 0)
    {
      tmp.push_back(this->command[i]);
      i++;
    }
  return (tmp);
}

std::string	Cmd::getValue() const
{
  int		i = 0;
  std::string	tmp;

  if (this->command.find("(", 0) != std::string::npos)
    {
      while (this->command[i] != ' ')
	i++;
      i++;
      while (this->command[i] != '(')
	i++;
      i++;
      while (this->command[i] != ')')
        {
	  tmp += this->command[i];
	  i++;
        }
      return (tmp);
    }
  return (NULL);
}

std::string	Cmd::getType() const
{
  int		i = 0;
  std::string	tmp;

  while (this->command[i] != ' ')
    i++;
  i++;
  while (this->command[i] != '(')
    {
      tmp += this->command[i];
      i++;
    }
  return (tmp);
}
