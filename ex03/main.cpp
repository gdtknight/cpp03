#include "DiamondTrap.hpp"

int main(void) {
  DiamondTrap diamond("DT-1");

  diamond.attack("target");
  diamond.takeDamage(50);
  diamond.beRepaired(30);

  diamond.whoAmI();
  diamond.highFivesGuys();
  diamond.guardGate();

  return 0;
}
