#include "DiamondTrap.hpp"

/*
 * main - DiamondTrap 테스트
 *
 * DiamondTrap을 생성하고 다양한 동작을 테스트합니다:
 * - 공격 (ScavTrap의 attack 사용)
 * - 피해 입기
 * - 수리
 * - whoAmI (DiamondTrap 전용)
 * - highFivesGuys (FragTrap에서 상속)
 * - guardGate (ScavTrap에서 상속)
 */
int main(void) {
  /* DiamondTrap 생성 */
  DiamondTrap diamond("DT-1");

  /* 기본 행동 테스트 */
  diamond.attack("target");
  diamond.takeDamage(50);
  diamond.beRepaired(30);

  /* 특수 능력 테스트 */
  diamond.whoAmI();
  diamond.highFivesGuys();
  diamond.guardGate();

  return 0;
}
