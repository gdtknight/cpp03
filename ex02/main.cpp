/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:50:01 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/17 17:45:37 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

static void printSeparator(const std::string& title) {
  std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main(void) {
  printSeparator("생성자 테스트 - 3가지 클래스");
  ClapTrap clap("CT-Base");
  ScavTrap scav("ST-Guard");
  FragTrap frag("FT-Bomber");

  printSeparator("상속 계층 구조 테스트");
  std::cout << "[ClapTrap 공격]" << std::endl;
  clap.attack("target");
  std::cout << "\n[ScavTrap 공격 (오버라이드)]" << std::endl;
  scav.attack("target");
  std::cout << "\n[FragTrap 공격 (기본 상속)]" << std::endl;
  frag.attack("target");

  printSeparator("ScavTrap 특수 능력");
  scav.takeDamage(30);
  scav.beRepaired(15);
  scav.guardGate();

  printSeparator("FragTrap 특수 능력");
  frag.takeDamage(40);
  frag.beRepaired(20);
  frag.highFivesGuys();

  printSeparator("복사 생성자 테스트");
  FragTrap frag2(frag);
  frag2.attack("clone_enemy");
  frag2.highFivesGuys();

  printSeparator("대입 연산자 테스트");
  ScavTrap scav2("ST-Temp");
  scav2 = scav;
  scav2.guardGate();

  printSeparator("에너지 및 체력 한계 테스트");
  FragTrap frag3("FT-Test");
  for (int i = 0; i < 100; i++) {
    frag3.attack("dummy");
  }
  frag3.attack("no_energy");
  
  FragTrap frag4("FT-Dead");
  frag4.takeDamage(100);
  frag4.attack("dead_attack");
  frag4.highFivesGuys();

  printSeparator("모든 클래스 비교");
  ClapTrap* robots[3];
  robots[0] = &clap;
  robots[1] = &scav;
  robots[2] = &frag;
  
  for (int i = 0; i < 3; i++) {
    robots[i]->attack("polymorphism_test");
  }

  printSeparator("소멸자 호출 순서 확인 (종료 시)");
  return 0;
}
