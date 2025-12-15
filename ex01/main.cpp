/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:50:01 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/14 20:50:01 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
 * main - ScavTrap 테스트
 *
 * ClapTrap과 ScavTrap을 생성하고 다양한 동작을 테스트합니다:
 * - 상태 확인
 * - 공격
 * - 피해 입기
 * - 수리
 * - ScavTrap 특수 능력 (guardGate)
 */
int main(void) {
  /* ClapTrap과 ScavTrap 생성 */
  ClapTrap clap("CT-1");
  ScavTrap scav("ST-1");

  /* 초기 상태 출력 */
  clap.status();
  scav.status();
  
  /* 공격 테스트 */
  clap.attack("target");
  scav.attack("target");
  
  /* 공격 후 상태 출력 */
  clap.status();
  scav.status();

  /* 피해, 수리, 특수 능력 테스트 */
  scav.takeDamage(30);
  scav.beRepaired(20);
  scav.guardGate();

  return 0;
}
