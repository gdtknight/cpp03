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

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

static void printSeparator(const std::string &title) {
  std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main(void) {
  printSeparator("생성자 테스트 - 3가지 클래스");
  ClapTrap clap("CT-Base");
  ScavTrap scav("ST-Base-1");
  FragTrap frag("FT-Base-1");

  printSeparator("상속 계층 구조 테스트");
  std::cout << "[ClapTrap 공격]" << std::endl;
  clap.attack("target");
  std::cout << "\n[ScavTrap 공격 (오버라이드)]" << std::endl;
  scav.attack("target");
  std::cout << "\n[FragTrap 공격 (기본 상속)]" << std::endl;
  frag.attack("target");
  frag.takeDamage(40);
  frag.beRepaired(20);

  printSeparator("FragTrap 특수 능력");
  frag.highFivesGuys();

  printSeparator("복사 생성자 테스트");
  FragTrap frag2(frag);
  frag.status();
  frag2.status();
  frag2.attack("clone_enemy");
  frag2.highFivesGuys();

  printSeparator("대입 연산자 테스트");
  FragTrap frag3;
  frag3.status();
  frag3 = frag;
  frag3.status();

  printSeparator("에너지 테스트");
  FragTrap frag4("FT-Test");
  for (int i = 0; i < 100; i++) {
    frag4.attack("dummy");
  }
  frag4.attack("no_energy");

  printSeparator("체력 한계 테스트");
  FragTrap frag5("FT-Dead");
  frag5.takeDamage(100);
  frag5.attack("dead_attack");
  frag5.highFivesGuys();

  printSeparator("모든 클래스 비교");
  ClapTrap *robots[3];
  robots[0] = &clap;
  robots[1] = &scav;
  robots[2] = &frag;

  for (int i = 0; i < 3; i++) {
    robots[i]->attack("polymorphism_test");
  }

  printSeparator("소멸자 호출 순서 확인 (종료 시)");
  return 0;
}
