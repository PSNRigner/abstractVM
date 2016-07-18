//
// Cmd.cpp for  in /home/velly_a/VM
// 
// Made by adrien velly$
// Login   <velly_a@epitech.net>
// 
// Started on  14 Jul 14 10:28 AM 2016 adrien velly
// Last update Mon Jul 18 11:16:06 2016 adrien velly
//

#include "Cmd.hh"
#include "AbstractVM.hh"

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

void		Cmd::verif_cmd(void) const
{
  if (this->command.find(";", 0) != std::string::npos)
    return ;
}

std::string     Cmd::getCommand() const
{
  int		i = 0;
  std::string	tmp;

  verif_cmd();
  while ((this->command[i] != ' ' && this->command[i] != '\t') && this->command[i] != 0)
    {
      tmp.push_back(this->command[i]);
      i++;
    }
  return (tmp);
}

std::string     Cmd::getV() const
{
  int		i = 0;
  std::string   tmp;

  verif_cmd();
  while (this->command[i] != ' ' && this->command[i] != '\t')
    i++;
  while (this->command[i] == ' ' || this->command[i] == '\t')
    i++;
  while (this->command[i] != 0)
    {
      tmp += this->command[i];
      i++;
    }
  return (tmp);
}

std::string	Cmd::getValue() const
{
  int		i = 0;
  std::string	tmp;

  verif_cmd();
  if (this->command.find("(", 0) != std::string::npos)
    {
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

  verif_cmd();
  while (this->command[i] != ' ' && this->command[i] != '\t')
    i++;
  while (this->command[i] == ' ' || this->command[i] == '\t')
    i++;
  while (this->command[i] != '(' && this->command[i] != ' ' && this->command[i] != '\t')
    {
      tmp += this->command[i];
      i++;
    }
  return (tmp);
}
