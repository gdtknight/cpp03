/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:33:24 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/14 19:50:13 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
  public:
  // Constructors & Destructor
  ClapTrap(void);
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &other);
  ClapTrap(const std::string &name,
           unsigned int       hitPoints,
           unsigned int       energyPoints,
           unsigned int       attackDamage);
  virtual ~ClapTrap(void);

  ClapTrap &operator=(const ClapTrap &other);

  // Actions
  void      attack(const std::string &target);
  void      takeDamage(unsigned int amount);
  void      beRepaired(unsigned int amount);
  void      status(void);

  protected:
  std::string  _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

  // Strongly-typed Action enum
  enum Action { ATTACK, REPAIR, TAKE_DAMAGE };

  // Private helpers
  bool        _canPerform(Action action) const;
  void        _printCannotAct(Action action) const;
  std::string _getActionStr(Action action) const;
};

#endif
