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

static void printSeparator(const std::string& title) {
  std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main(void) {
  printSeparator("생성자 테스트");
  ClapTrap clap1("Warrior");
  ClapTrap clap2("Mage");
  ClapTrap clap3;
  ClapTrap clap4(clap1);

  printSeparator("기본 공격 테스트");
  clap1.attack("Mage");
  clap2.takeDamage(0);
  clap2.attack("Warrior");

  printSeparator("수리 테스트");
  clap2.beRepaired(5);
  clap2.beRepaired(3);

  printSeparator("에너지 소진 테스트 (10회 공격)");
  for (int i = 0; i < 10; i++) {
    clap1.attack("dummy");
  }
  
  printSeparator("에너지 부족 상태 테스트");
  clap1.attack("target");
  clap1.beRepaired(10);

  printSeparator("체력 소진 테스트");
  clap2.takeDamage(10);
  clap2.takeDamage(5);
  clap2.attack("target");
  clap2.beRepaired(5);

  printSeparator("복사 대입 연산자 테스트");
  ClapTrap clap5("Original");
  clap5.attack("enemy");
  ClapTrap clap6("Copy");
  clap6 = clap5;

  printSeparator("소멸자 테스트 (프로그램 종료 시)");
  return 0;
}
