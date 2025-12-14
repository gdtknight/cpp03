/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:08 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/12 13:57:08 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               CONSTRUCTORS                                 */
/* ************************************************************************** */

FragTrap::FragTrap(void)
  : ClapTrap("default",
             100,
             50,
             20) {
  std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
  : ClapTrap(name,
             100,
             50,
             20) {
  std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
  : ClapTrap(other) {
  std::cout << "FragTrap copy constructor called" << std::endl;
  *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap copy assignment operator called" << std::endl;
  if (this != &other)
    ClapTrap::operator=(other);
  return *this;
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

/* ************************************************************************** */
/*                                  ACTIONS                                   */
/* ************************************************************************** */

void FragTrap::highFivesGuys() const {
  std::cout << "FragTrap " << _name << " requests a high five! ✋" << std::endl;
}
