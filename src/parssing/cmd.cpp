//
// VM.cpp for  in /home/velly_a/VM
// 
// Made by adrien velly$
// Login   <velly_a@epitech.net>
// 
// Started on  14 Jul 14 10:28 AM 2016 adrien velly
// Last update 14 Jul 14 10:28 AM 2016 adrien velly
//

#include "cmd.hpp"

Cmd::Cmd(const std::string &commande)
{
    setCommande(commande);
}

void     Cmd::setCommande(const std::string &value)
{
    this->commande = value;
}

Cmd::~Cmd()
{
    this->commande.erase();
}

std::string     Cmd::getCommande() const
{
    int         i = 0;
    std::string tmp;

    while (this->commande[i] != ' ' && this->commande[i] != 0)
    {
        tmp.push_back(this->commande[i]);
        i++;
    }
    return (tmp);
}

std::string Cmd::getValue() const
{
    int         i = 0;
    std::string tmp;

    if (this->commande[i].find("(", 0) != std::string::npos)
    {
        while (this->commande[i] != ' ')
            i++;
        i++;
        while (this->commande[i] != '(')
            i++;
        i++;
        while (this->commande[i] != ')')
        {
            tmp += this->commande[i];
            i++;
        }
        return (tmp);
    }
    return (NULL);
}

std::string Cmd::getType() const
{
    int         i = 0;
    int         j = 0;
    std::string tmp;

    while (this->commande[i] != ' ')
        i++;
    i++;
    while (this->commande[i] != '(')
    {
        tmp += this->commande[i];
        i++;
    }
    return (tmp);
}