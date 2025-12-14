/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:38:18 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/14 19:38:18 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
  : ClapTrap("default_clap_name")
  , ScavTrap()
  , FragTrap()
  , _name("default") {
  _hitPoints    = FragTrap::_hitPoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;
  std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
  : ClapTrap(name + "_clap_name")
  , ScavTrap(name)
  , FragTrap(name)
  , _name(name) {
  _hitPoints    = FragTrap::_hitPoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;
  std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
  : ClapTrap(other)
  , ScavTrap(other)
  , FragTrap(other) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
  *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap copy assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
    _name = other._name;
  }
  return *this;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap name: " << _name << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
