//
// Parsing.hh for  in /home/velly_a/VM
// 
// Made by adrien velly$
// Login   <velly_a@epitech.net>
// 
// Started on  14 Jul 14 9:30 AM 2016 adrien velly
// Last update Thu Jul 14 15:09:38 2016 loic frasse-mathon
//

#ifndef PARSING
# define PARSING

# include <stdio.h>
# include <stdlib.h>
# include <string>
# include <iostream>
# include <vector>
# include <fstream>
# include <unistd.h>
# include "Cmd.hh"

class                           Parsing
{
public:
  Parsing(void);
  Parsing(const std::string &file_name);
  ~Parsing(void);
  std::string			getFile_name(void) const;
  void				setFile_name(const std::string &file_name);
  void				setList_cmd(void);
  void				make_cmd(void);
  std::vector<Cmd>		getList_obj(void) const;
  std::vector<std::string>	getList_cmd() const;

private:
  std::string			file_name;
  std::vector<std::string>	list_cmd;
  std::vector<Cmd>		list_obj;
};


#endif //PARSING
