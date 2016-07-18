//
// BigDecimal.cpp for  in /home/frasse_l/Projets/abstractVM
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Thu Jul 14 11:32:42 2016 loic frasse-mathon
// Last update Mon Jul 18 14:47:38 2016 loic frasse-mathon
//

#include <iostream>
#include <algorithm>
#include "BigDecimal.hh"
#include "Exceptions.hh"

BigDecimal::BigDecimal(const std::string &value)
{
  this->data = value;
}

BigDecimal::~BigDecimal()
{
}

static void	bdSub(std::string &, std::string &, std::string &);
static void	bdMul(std::string &, std::string &, std::string &);

static void	bdAdd(std::string &str1, std::string &str2, std::string &result)
{
  bool		neg[2];
  size_t	virg[2];
  size_t	i;
  int		ret;

  neg[0] = str1[0] == '-';
  neg[1] = str2[0] == '-';
  if (neg[0] && neg[1])
    {
      str1 = str1.substr(1, str1.size() - 1);
      str2 = str2.substr(1, str2.size() - 1);
    }
  else if (neg[0] && !neg[1])
    {
      str1 = str1.substr(1, str1.size() - 1);
      bdSub(str2, str1, result);
      return ;
    }
  else if (neg[1] && !neg[0])
    {
      str2 = str2.substr(1, str2.size() - 1);
      bdSub(str1, str2, result);
      return ;
    }
  i = 0;
  ret = 0;
  virg[0] = str1.find('.');
  virg[1] = str2.find('.');
  if (virg[0] == std::string::npos)
    virg[0] = str1.size();
  if (virg[1] == std::string::npos)
    virg[1] = str2.size();
  i = str1.size() - virg[0] > str2.size() - virg[1] ? str1.size() - virg[0] : str2.size() - virg[1];
  if (i > 1)
    {
      while (i > 1)
	{
	  int	sum = i + virg[0] - 1 < str1.size() ? str1[i + virg[0] - 1] - '0' : 0;
	  sum += i + virg[1] - 1 < str2.size() ? str2[i + virg[1] - 1] - '0' : 0;
	  ret = sum / 10;
	  result.push_back((sum % 10) + '0');
	  i--;
	}
      result.push_back('.');
    }
  i = 0;
  while (i < virg[0] && i < virg[1])
    {
      int	sum = str1[virg[0] - 1 - i] - '0' + str2[virg[1] - 1 - i] - '0' + ret;
      ret = sum / 10;
      result.push_back((sum % 10) + '0');
      i++;
    }
  while (i < virg[0] || i < virg[1])
    {
      int	sum = (i < virg[0] ? str1[virg[0] - 1 - i] : str2[virg[1] - 1 - i]) - '0' + ret;
      ret = sum / 10;
      result.push_back((sum % 10) + '0');
      i++;
    }
  if (ret != 0)
    result.push_back(ret + '0');
  if (neg[0] && neg[1])
    result.push_back('-');
  std::reverse(result.begin(), result.end());
}

static bool	isGreater(const std::string &str1, const std::string &str2)
{
  bool	rev = false;
  std::string	tmp1 = str1.substr(0, str1.find('.') == std::string::npos ? str1.size() : str1.find('.'));
  std::string	tmp2 = str2.substr(0, str2.find('.') == std::string::npos ? str2.size() : str2.find('.'));
  if (tmp1[0] == '-' && tmp2[0] != '-')
    return (false);
  if (tmp2[0] == '-' && tmp1[0] != '-')
    return (true);
  if (tmp1[0] == '-' && tmp2[0] == '-')
    {
      rev = true;
      tmp1 = tmp1.substr(1, tmp1.size() - 1);
      tmp2 = tmp2.substr(1, tmp2.size() - 1);
    }
  if (tmp1.size() != tmp2.size())
    return (rev ? tmp1.size() < tmp2.size() : tmp1.size() > tmp2.size());
  if (tmp1 != tmp2)
    return (rev ? tmp2 > tmp1 : tmp1 > tmp2);
  tmp1 = str1.find('.') == std::string::npos ? "" : str1.substr(str1.find('.') + 1, str1.size() - str1.find('.') - 1);
  tmp2 = str2.find('.') == std::string::npos ? "" : str2.substr(str2.find('.') + 1, str2.size() - str2.find('.') - 1);
  return (rev ? tmp2 > tmp1 : tmp1 > tmp2);
}

static void	bdSub(std::string &str1, std::string &str2, std::string &result)
{
  bool		neg[2];
  size_t	i;
  size_t	virg[2];
  int		ret;

  neg[0] = str1[0] == '-';
  neg[1] = str2[0] == '-';
  if (neg[0] && neg[1])
    {
      str1 = str1.substr(1, str1.size() - 1);
      str2 = str2.substr(1, str2.size() - 1);
      std::string tmp1;
      std::string tmp2 = "-1";
      bdSub(str2, str1, tmp1);
      std::cout << tmp1 << std::endl;
      bdMul(tmp1, tmp2, result);
      return ;
    }
  else if (!neg[0] && neg[1])
    {
      str2 = str2.substr(1, str2.size() - 1);
      bdAdd(str1, str2, result);
      return ;
    }
  else if (neg[0] && !neg[1])
    {
      str1 = str1.substr(1, str1.size() - 1);
      bdAdd(str1, str2, result);
      std::reverse(result.begin(), result.end());
      result.push_back('-');
      std::reverse(result.begin(), result.end());
      return ;
    }
  if (isGreater(str2, str1))
    {
      std::string	tmp;
      std::string	tmp2 = "-1";
      bdSub(str2, str1, tmp);
      bdMul(tmp, tmp2, result);
      return ;
    }
  virg[0] = str1.find('.');
  virg[1] = str2.find('.');
  if (virg[0] == std::string::npos)
    virg[0] = str1.size();
  if (virg[1] == std::string::npos)
    virg[1] = str2.size();
  i = str1.size() - virg[0] > str2.size() - virg[1] ? str1.size() - virg[0] : str2.size() - virg[1];
  ret = 0;
  if (i > 1)
    {
      while (i > 1)
	{
	  int	sum = i + virg[0] - 1 < str1.size() ? str1[i + virg[0] - 1] - '0' : 0;
	  sum -= i + virg[1] - 1 < str2.size() ? str2[i + virg[1] - 1] - '0' : 0;
	  ret = (sum < 0) * -1;
	  result.push_back((sum >= 0 ? sum % 10 : 10 - (sum % 10)) + '0');
	  i--;
	}
      result.push_back('.');
    }
  i = 0;
  while (i < virg[0] && i < virg[1])
    {
      int	sum = str1[virg[0] - 1 - i] - '0' - str2[virg[1] - 1 - i] + '0' + ret;
      ret = (sum < 0) * -1;
      result.push_back((sum >= 0 ? sum % 10 : 10 + (sum % 10)) + '0');
      i++;
    }
  while (i < virg[0] || i < virg[1])
    {
      int	sum = (i < virg[0] ? str1[virg[0] - 1 - i] : str2[virg[1] - 1 - i]) - '0' + ret;
      ret = (sum < 0) * -1;
      result.push_back((sum >= 0 ? sum % 10 : 10 + (sum % 10)) + '0');
      i++;
    }
  if (ret != 0)
    result.push_back(ret + '0');
  if (neg[0] && neg[1])
    result.push_back('-');
  std::reverse(result.begin(), result.end());
  while (result.size() > 1 && result[0] == '0' && result[1] != '.')
    result.erase(result.begin());
}

static void			bdMul(std::string &str1, std::string &str2, std::string &result)
{
  size_t			virg[2];
  std::vector<std::string>	sums;
  size_t			i;
  size_t			j;
  size_t			ret;
  size_t			k;
  bool				neg[2];

  neg[0] = str1[0] == '-';
  neg[1] = str2[0] == '-';
  if (neg[0])
    str1 = str1.substr(1, str1.size() - 1);
  if (neg[1])
    str2 = str2.substr(1, str2.size() - 1);
  virg[0] = str1.find('.');
  if (virg[0] != std::string::npos)
    virg[0] = str1.size() - 1 - virg[0];
  virg[1] = str2.find('.');
  if (virg[1] != std::string::npos)
    virg[1] = str2.size() - 1 - virg[1];
  str1.erase(std::remove(str1.begin(), str1.end(), '.'), str1.end());
  str2.erase(std::remove(str2.begin(), str2.end(), '.'), str2.end());
  i = 0;
  while (i < str1.size())
    {
      int		n = str1[str1.size() - i - 1] - '0';
      std::string	tmp;
      j = 0;
      ret = 0;
      while (j < str2.size())
	{
	  int	sum = str2[str2.size() - j - 1] - '0';
	  sum *= n;
	  sum += ret;
	  ret = sum / 10;
	  tmp.push_back((sum % 10) + '0');
	  j++;
	}
      if (ret != 0)
	tmp.push_back(ret + '0');
      std::reverse(tmp.begin(), tmp.end());
      k = 0;
      while (k < i)
	{
	  tmp.push_back('0');
	  k++;
	}
      sums.push_back(tmp);
      i++;
    }
  std::string	tmp = sums[0];
  std::string	result2;
  i = 1;
  while (i < sums.size())
    {
      std::string	tmp2 = sums[i];
      result2.clear();
      bdAdd(tmp, tmp2, result2);
      tmp = result2;
      i++;
    }
  result = tmp;
  if (virg[0] != std::string::npos || virg[1] != std::string::npos)
    {
      size_t	n = virg[0] != std::string::npos ? virg[0] : 0;
      n += virg[1] != std::string::npos ? virg[1] : 0;
      result.insert(result.size() - n, ".");
    }
  if ((neg[0] && !neg[1]) || (neg[1] && !neg[0]))
    result = std::string("-") + result;
  while (result.size() > 1 && result[0] == '0' && result[1] != '.')
    result.erase(result.begin());
}

/*static void		bdDiv(std::string &str1, std::string &str2, std::string &result)
{
  size_t	virg[2];
  bool		neg[2];
  size_t	i;
  size_t	j;
  std::string	tmp;
  std::string	plaige;
  std::string	plaige2;
  bool		k;

  plaige = str1;
  plaige2 = str2;
  neg[0] = str1[0] == '-';
  neg[1] = str2[0] == '-';
  if (neg[0])
    str1 = str1.substr(1, str1.size() - 1);
  if (neg[1])
    str2 = str2.substr(1, str2.size() - 1);
  virg[0] = str1.find('.');
  virg[1] = str2.find('.');
  str1.erase(std::remove(str1.begin(), str1.end(), '.'), str1.end());
  str2.erase(std::remove(str2.begin(), str2.end(), '.'), str2.end());
  i = 0;
  k = true;
  while (i < str2.size() - 1 && i < str1.size() - 1)
    {
      tmp.push_back(str1[i]);
      i++;
    }
  do
    {
      tmp.push_back(i < str1.size() ? str1[i] : '0');
      j = 0;
      while (j < 10)
	{
	  std::string	tmp2;
	  tmp2.push_back(j + '0');
	  std::string	tmp3;
	  bdMul(str2, tmp2, tmp3);
	  if (isGreater(tmp3, tmp))
	    break ;
	  j++;
	}
      j--;
      std::string	tmp2;
      tmp2.push_back(j + '0');
      std::string	tmp3;
      bdMul(str2, tmp2, tmp3);
      tmp2.clear();
      bdSub(tmp, tmp3, tmp2);
      tmp = tmp2;
      tmp2.clear();
      bdSub(plaige, tmp3, tmp2);
      plaige = tmp2;
      result.push_back('0' + j);
      if (k && isGreater(plaige2, plaige))
	{
	  result.push_back('.');
	  k = false;
	}
      i++;
    }
  while (tmp != "0");
  (void)virg;
  while (result.size() > 1 && result[0] == '0' && result[1] != '.')
    result.erase(result.begin());
  if (result.size() > 0 && result.back() == '.')
    result.pop_back();
    }*/

IOperand	*BigDecimal::operator+(const IOperand &op) const
{
  std::string	tmp1;
  std::string	tmp2;
  std::string	result;

  tmp1 = this->data;
  tmp2 = op.toString();
  bdAdd(tmp1, tmp2, result);
  return (new BigDecimal(result));
}

IOperand	*BigDecimal::operator-(const IOperand &op) const
{
  std::string	tmp1;
  std::string	tmp2;
  std::string	result;

  tmp1 = this->data;
  tmp2 = op.toString();
  bdSub(tmp1, tmp2, result);
  return (new BigDecimal(result));
}

IOperand	*BigDecimal::operator*(const IOperand &op) const
{
  std::string	tmp1;
  std::string	tmp2;
  std::string	result;

  tmp1 = this->data;
  tmp2 = op.toString();
  bdMul(tmp1, tmp2, result);
  return (new BigDecimal(result));
}

IOperand	*BigDecimal::operator/(const IOperand &op) const
{
  (void)op;
  throw new NotYetSupportedException;
  /* TODO */
}

IOperand	*BigDecimal::operator%(const IOperand &op) const
{
  (void)op;
  throw new NotYetSupportedException;
  /* TODO */
}

eOperandType::eOperandType	BigDecimal::getType() const
{
  return (eOperandType::BigDecimal);
}

std::string	BigDecimal::toString() const
{
  return (this->data);
}
