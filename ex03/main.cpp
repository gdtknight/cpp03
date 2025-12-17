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

#include "DiamondTrap.hpp"
#include <iostream>

static void printSeparator(const std::string& title) {
  std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main(void) {
  printSeparator("다이아몬드 상속 생성자 테스트");
  DiamondTrap diamond1("DT-Hybrid");
  DiamondTrap diamond2;

  printSeparator("DiamondTrap 고유 기능 - whoAmI");
  diamond1.whoAmI();
  diamond2.whoAmI();

  printSeparator("다중 상속 - attack 메서드 (ScavTrap에서)");
  diamond1.attack("enemy");
  diamond1.attack("another_enemy");

  printSeparator("ScavTrap에서 상속된 특수 능력");
  diamond1.guardGate();

  printSeparator("FragTrap에서 상속된 특수 능력");
  diamond1.highFivesGuys();

  printSeparator("ClapTrap에서 상속된 메서드");
  diamond1.takeDamage(50);
  diamond1.beRepaired(30);
  diamond1.takeDamage(20);

  printSeparator("복사 생성자 테스트");
  DiamondTrap diamond3(diamond1);
  diamond3.whoAmI();
  diamond3.attack("clone_target");

  printSeparator("대입 연산자 테스트");
  DiamondTrap diamond4("DT-Temp");
  diamond4 = diamond1;
  diamond4.whoAmI();
  diamond4.attack("assigned_target");

  printSeparator("에너지 소진 테스트 (ScavTrap의 50 에너지)");
  for (int i = 0; i < 50; i++) {
    diamond1.attack("dummy");
  }
  diamond1.attack("no_energy");

  printSeparator("체력 소진 테스트 (FragTrap의 100 HP)");
  DiamondTrap diamond5("DT-Dying");
  diamond5.takeDamage(100);
  diamond5.attack("dead_attack");
  diamond5.whoAmI();
  diamond5.guardGate();
  diamond5.highFivesGuys();

  printSeparator("다이아몬드 상속 구조 확인");
  std::cout << "DiamondTrap은 ScavTrap과 FragTrap을 상속" << std::endl;
  std::cout << "ScavTrap과 FragTrap은 모두 ClapTrap을 virtual 상속" << std::endl;
  std::cout << "따라서 ClapTrap 인스턴스는 하나만 존재" << std::endl;
  diamond1.whoAmI();

  printSeparator("모든 기능 종합 테스트");
  DiamondTrap diamond6("DT-Final");
  diamond6.attack("target1");
  diamond6.takeDamage(30);
  diamond6.beRepaired(20);
  diamond6.guardGate();
  diamond6.highFivesGuys();
  diamond6.whoAmI();

  printSeparator("소멸자 호출 순서 확인 (종료 시)");
  std::cout << "DiamondTrap -> ScavTrap -> FragTrap -> ClapTrap 순서" << std::endl;
  return 0;
}
