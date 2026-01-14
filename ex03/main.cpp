/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:50:01 by yoshin            #+#    #+#             */
/*   Updated: 2026/01/14 11:14:58 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

static void printSeparator(const std::string &title) {
  std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main(void) {
  printSeparator("다이아몬드 상속 생성자 테스트");
  DiamondTrap diamond1("DT-Hybrid");
  DiamondTrap dt_default;

  printSeparator("DiamondTrap 고유 기능 - whoAmI");
  diamond1.whoAmI();
  dt_default.whoAmI();

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

  printSeparator("복사 생성자 테스트");
  DiamondTrap diamond3(diamond1);
  diamond3.whoAmI();
  diamond3.attack("clone_target");

  printSeparator("대입 연산자 테스트");
  DiamondTrap diamond4("DT-Temp");
  diamond4.status();
  diamond4.whoAmI();
  diamond4 = diamond1;
  diamond4.status();
  diamond4.whoAmI();

  printSeparator("에너지 소진 테스트 (ScavTrap의 50 에너지)");
  DiamondTrap diamond5("DT-Energy");
  for (int i = 0; i < 50; i++) {
    diamond5.attack("dummy");
  }
  diamond5.attack("no_energy");

  printSeparator("체력 소진 테스트 (FragTrap의 100 HP)");
  DiamondTrap diamond6("DT-Dying");
  diamond6.takeDamage(100);
  diamond6.attack("dead_attack");
  diamond6.whoAmI();
  diamond6.guardGate();
  diamond6.highFivesGuys();

  printSeparator("다이아몬드 상속 구조 확인");

  // DiamondTrap* -> ScavTrap* / FragTrap* 로 올라간 뒤
  // 다시 ClapTrap* 로 내려오게 만들어서,
  // ClapTrap 서브오브젝트가 하나인지(virtual) 두 개인지(비-virtual) 확인.
  DiamondTrap *d    = &diamond1;

  ClapTrap *viaScav = static_cast<ClapTrap *>(static_cast<ScavTrap *>(d));
  ClapTrap *viaFrag = static_cast<ClapTrap *>(static_cast<FragTrap *>(d));

  std::cout << "ClapTrap* via ScavTrap: " << viaScav << std::endl;
  std::cout << "ClapTrap* via FragTrap: " << viaFrag << std::endl;

  if (viaScav == viaFrag)
    std::cout << "=> ClapTrap subobject is SINGLE (virtual inheritance) ✅\n";
  else
    std::cout << "=> ClapTrap subobject is DUPLICATED (non-virtual) ❌\n";

  diamond1.whoAmI();

  printSeparator("소멸자 호출 순서 확인 (종료 시)");
  return 0;
}
