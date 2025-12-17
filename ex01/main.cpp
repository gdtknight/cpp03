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
#include <iostream>

static void printSeparator(const std::string& title) {
  std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main(void) {
  printSeparator("생성자 테스트 - ClapTrap과 ScavTrap");
  ClapTrap clap("CT-Base");
  ScavTrap scav1("ST-Guard");
  ScavTrap scav2;

  printSeparator("상속 관계 테스트 - 공격 메서드 오버라이드");
  std::cout << "[ClapTrap의 attack]" << std::endl;
  clap.attack("enemy");
  std::cout << "\n[ScavTrap의 attack (오버라이드)]" << std::endl;
  scav1.attack("enemy");

  printSeparator("상속된 메서드 테스트 - takeDamage & beRepaired");
  scav1.takeDamage(30);
  scav1.beRepaired(20);
  scav1.takeDamage(50);
  scav1.beRepaired(10);

  printSeparator("ScavTrap 특수 능력 테스트 - guardGate");
  scav1.guardGate();
  scav2.guardGate();

  printSeparator("복사 생성자 테스트");
  ScavTrap scav3(scav1);
  scav3.attack("clone_target");
  scav3.guardGate();

  printSeparator("대입 연산자 테스트");
  ScavTrap scav4("ST-Temp");
  scav4 = scav1;
  scav4.attack("assigned_target");

  printSeparator("에너지 소진 테스트 (50회 공격)");
  for (int i = 0; i < 50; i++) {
    scav1.attack("dummy");
  }
  scav1.attack("no_energy");

  printSeparator("체력 소진 테스트");
  ScavTrap scav5("ST-Dying");
  scav5.takeDamage(100);
  scav5.attack("dead_attack");
  scav5.guardGate();

  printSeparator("소멸자 호출 순서 확인 (종료 시)");
  return 0;
}
