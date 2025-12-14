/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:13:24 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/12 15:23:59 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"
#include <iostream>
#include <stdexcept>

/* ************************************************************************** */
/*                               CONSTRUCTORS                                 */
/* ************************************************************************** */

ClapTrap::ClapTrap()
  : _name("default")
  , _hitPoints(10)
  , _energyPoints(10)
  , _attackDamage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
  : _name(name)
  , _hitPoints(10)
  , _energyPoints(10)
  , _attackDamage(0) {
  std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

// Protected constructor for derived classes
ClapTrap::ClapTrap(const std::string &name,
                   unsigned int       hitPoints,
                   unsigned int       energyPoints,
                   unsigned int       attackDamage)
  : _name(name)
  , _hitPoints(hitPoints)
  , _energyPoints(energyPoints)
  , _attackDamage(attackDamage) {
  std::cout << "ClapTrap " << _name << " extended constructor called"
            << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
  : _name(other._name)
  , _hitPoints(other._hitPoints)
  , _energyPoints(other._energyPoints)
  , _attackDamage(other._attackDamage) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    _name         = other._name;
    _hitPoints    = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  std::cout << "ClapTrap copy assignment operator called" << std::endl;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

/* ************************************************************************** */
/*                               PRIVATE HELPERS                              */
/* ************************************************************************** */

std::string ClapTrap::_getActionStr(Action action) const {
  switch (action) {
  case ATTACK:
    return ("attack");
  case REPAIR:
    return ("be repaired");
    break;
  case TAKE_DAMAGE:
    return ("take damage");
  }
  throw std::runtime_error("Invalid args");
}

void ClapTrap::_printCannotAct(Action action) const {
  try {
    if (_hitPoints == 0) {
      std::cout << "ClapTrap " << _name << " cannot " << _getActionStr(action)
                << " (It is dead)" << std::endl;
      return;
    }
    std::cout << "ClapTrap " << _name << " cannot " << _getActionStr(action)
              << " (No energy points left)" << std::endl;
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }
}

bool ClapTrap::_canPerform(Action action) const {
  if (_hitPoints == 0 || ((action != TAKE_DAMAGE) && _energyPoints == 0)) {
    _printCannotAct(action);
    return false;
  }
  return true;
}

/* ************************************************************************** */
/*                                  ACTIONS                                   */
/* ************************************************************************** */

void ClapTrap::attack(const std::string &target) {
  if (!_canPerform(ATTACK))
    return;
  --_energyPoints;

  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!_canPerform(REPAIR))
    return;
  --_energyPoints;
  _hitPoints += amount;

  std::cout << "ClapTrap " << _name << " is repaired for " << amount
            << " points!" << std::endl
            << "Hit points: " << _hitPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!_canPerform(TAKE_DAMAGE))
    return;

  _hitPoints = (amount >= _hitPoints) ? 0 : _hitPoints - amount;

  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage!" << std::endl
            << "Hit points: " << _hitPoints << std::endl;
}
