/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:49:13 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/17 17:45:37 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

static void printSeparator(const std::string &title) {
  std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main(void) {
  printSeparator("생성자 테스트");
  ClapTrap warrior1("Warrior1");
  ClapTrap mage1("Mage1");
  ClapTrap ct_default;
  ClapTrap ct_copied(warrior1);

  printSeparator("기본 공격 테스트");
  warrior1.attack("Mage");
  mage1.takeDamage(0);
  mage1.attack("Warrior");

  printSeparator("수리 테스트");
  mage1.beRepaired(5);
  mage1.beRepaired(3);

  printSeparator("에너지 소진 테스트 (10회 공격)");
  ClapTrap warrior2("Warrior2");
  for (int i = 0; i < 10; i++) {
    warrior2.attack("dummy");
  }

  printSeparator("에너지 부족 상태 테스트");
  warrior2.attack("target");
  warrior2.beRepaired(10);

  printSeparator("체력 소진 테스트");
  mage1.takeDamage(10);
  mage1.takeDamage(5);
  mage1.attack("target");
  mage1.beRepaired(5);

  printSeparator("복사 대입 연산자 테스트");
  ClapTrap clap5("CT-5");
  clap5.attack("enemy");
  clap5.status();
  ClapTrap clap6("CT-6");
  clap6.status();
  clap6 = clap5;
  clap6.status();

  printSeparator("소멸자 테스트 (프로그램 종료 시)");
  return 0;
}
