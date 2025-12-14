/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:49:13 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/14 19:51:20 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap clap1("CT-1");
  ClapTrap clap2("CT-2");
  ClapTrap clap3;

  clap1.attack("CT-2");
  clap2.takeDamage(0);
  clap2.beRepaired(5);
  clap3.attack("CT-1");

  for (int i = 0; i < 10; i++)
    clap1.attack("target");

  clap1.attack("target");

  return 0;
}
