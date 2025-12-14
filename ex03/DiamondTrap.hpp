/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:38:11 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/14 19:38:11 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
  public:
  DiamondTrap(void);
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap &other);
  DiamondTrap &operator=(const DiamondTrap &other);
  ~DiamondTrap(void);

  using ScavTrap::attack;
  void whoAmI(void);

  private:
  std::string _name;
};

#endif
