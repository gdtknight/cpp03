/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:50:01 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/14 20:50:01 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
  ClapTrap clap("CT-1");
  ScavTrap scav("ST-1");

  clap.status();
  scav.status();
  clap.attack("target");
  scav.attack("target");
  clap.status();
  scav.status();

  scav.takeDamage(30);
  scav.beRepaired(20);
  scav.guardGate();

  return 0;
}
