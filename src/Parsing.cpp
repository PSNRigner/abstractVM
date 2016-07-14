//
// Parsing.cpp for  in /home/velly_a/VM
// 
// Made by adrien velly$
// Login   <velly_a@epitech.net>
// 
// Started on  14 Jul 14 9:31 AM 2016 adrien velly
// Last update Thu Jul 14 22:57:35 2016 loic frasse-mathon
//

#include "Parsing.hh"

Parsing::Parsing(void)
{
  setList_cmd();
}

Parsing::Parsing(const std::string &file_name)
{
  std::ifstream		fichier(file_name.c_str());
  std::string		value;

  if (fichier)
    {
      while (getline(fichier, value))
	this->list_cmd.push_back(value);
      if (this->list_cmd.size() == 0)
	std::cerr << "File is empty" << std::endl;
      else
	make_cmd();
    }
  else
    std::cerr << "Can't open file" << std::endl;
}

Parsing::~Parsing()
{
  this->file_name.erase(this->file_name.begin(), this->file_name.end());
  this->list_cmd.erase(this->list_cmd.begin(), this->list_cmd.end());
  this->list_obj.erase(this->list_obj.begin(), this->list_obj.end());
}

void		Parsing::setList_cmd()
{
  std::string	tmp;

  while (std::getline(std::cin, tmp))
    {
      if (tmp == ";;")
	{
	  make_cmd();
	  return ;
	}
      this->list_cmd.push_back(tmp);
    }
  make_cmd();
}

void		Parsing::make_cmd()
{
  size_t	i = 0;

  while (i != this->list_cmd.size())
    {
      Cmd	cmd(this->list_cmd[i]);
      this->list_obj.push_back(cmd);
      i++;
    }
}

std::vector<std::string> Parsing::getList_cmd() const
{
  return (this->list_cmd);
}

std::vector<Cmd> Parsing::getList_obj() const
{
  return (this->list_obj);
}

void	Parsing::setFile_name(const std::string &file_name)
{
  this->file_name = file_name;
}

std::string	Parsing::getFile_name() const
{
  return (this->file_name);
}
