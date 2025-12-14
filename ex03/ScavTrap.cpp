/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:08 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/12 13:57:08 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               CONSTRUCTORS                                 */
/* ************************************************************************** */

ScavTrap::ScavTrap(void)
  : ClapTrap("default",
             100,
             50,
             20) {
  std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
  : ClapTrap(name,
             100,
             50,
             20) {
  std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
  : ClapTrap(other) {
  std::cout << "ScavTrap copy constructor called" << std::endl;
  *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap copy assignment operator called" << std::endl;
  if (this != &other)
    ClapTrap::operator=(other);
  return *this;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

/* ************************************************************************** */
/*                                  ACTIONS                                   */
/* ************************************************************************** */

void ScavTrap::attack(const std::string &target) {
  if (_energyPoints == 0) {
    std::cout << "ScavTrap " << _name << " has no energy points left!"
              << std::endl;
    return;
  }
  if (_hitPoints == 0) {
    std::cout << "ScavTrap " << _name << " is dead!" << std::endl;
    return;
  }
  _energyPoints--;
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode"
            << std::endl;
}
