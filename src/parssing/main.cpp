#include "parsing.hpp"


int main()
{
    Parsing pars;
    std::vector<Cmd>    list;
    std::vector<std::string> l_s;
    int                 i;


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
        std::cout << list[i].getCommande() << std::endl;
        i++;
    }
}