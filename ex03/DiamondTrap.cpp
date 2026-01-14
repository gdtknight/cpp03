/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:38:18 by yoshin            #+#    #+#             */
/*   Updated: 2026/01/13 21:07:53 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

/*
 * DiamondTrap::DiamondTrap - 기본 생성자
 *
 * 기본값으로 DiamondTrap을 생성합니다:
 * - DiamondTrap 이름: "default"
 * - ClapTrap 이름: "default_clap_name"
 * - 체력: FragTrap에서 상속 (100)
 * - 에너지: ScavTrap에서 상속 (50)
 * - 공격 데미지: FragTrap에서 상속 (30)
 */
DiamondTrap::DiamondTrap(void)
  : ClapTrap("default_clap_name",
             100,
             50,
             30)
  , ScavTrap()
  , FragTrap()
  , _name("default") {
  std::cout << "DiamondTrap default constructor called" << std::endl;
}

/*
 * DiamondTrap::DiamondTrap - 이름 생성자
 * @name: DiamondTrap의 이름
 *
 * 지정된 이름으로 DiamondTrap을 생성합니다.
 * ClapTrap 이름은 "<name>_clap_name"으로 설정됩니다.
 * 스탯은 FragTrap과 ScavTrap에서 조합됩니다.
 */
DiamondTrap::DiamondTrap(const std::string &name)
  : ClapTrap(name + "_clap_name",
             100,
             50,
             30)
  , ScavTrap(name)
  , FragTrap(name)
  , _name(name) {
  std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

/*
 * DiamondTrap::DiamondTrap - 복사 생성자
 * @other: 복사할 DiamondTrap 객체
 *
 * 다른 DiamondTrap의 모든 속성을 복사하여 새 DiamondTrap을 생성합니다.
 */
DiamondTrap::DiamondTrap(const DiamondTrap &other)
  : ClapTrap(other)
  , ScavTrap(other)
  , FragTrap(other)
  , _name(other._name) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
}

/*
 * DiamondTrap::operator= - 복사 대입 연산자
 * @other: 할당할 DiamondTrap 객체
 *
 * 다른 DiamondTrap의 속성을 이 DiamondTrap에 할당합니다.
 *
 * Return: 연쇄 할당을 위한 이 객체의 참조
 */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap copy assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
	DiamondTrap::_name = other.DiamondTrap::_name;
  }
  return *this;
}

/*
 * DiamondTrap::~DiamondTrap - 소멸자
 *
 * DiamondTrap을 파괴하고 메시지를 출력합니다.
 */
DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

/*
 * DiamondTrap::whoAmI - 신원 확인
 *
 * DiamondTrap의 이름과 ClapTrap의 이름을 모두 출력합니다.
 * 이것은 DiamondTrap 전용 특수 능력입니다.
 * 다이아몬드 상속에서 두 개의 별도 이름을 유지하는 것을 보여줍니다.
 */
void DiamondTrap::whoAmI(void) const {
  std::cout << "DiamondTrap name: " << _name << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

/* ************************************************************************** */
/*                          헬퍼 함수 (PROTECTED HELPERS)                     */
/* ************************************************************************** */

const char *DiamondTrap::_classTag() const { return "DiamondTrap"; }
