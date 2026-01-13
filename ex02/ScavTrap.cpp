/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:08 by yoshin            #+#    #+#             */
/*   Updated: 2026/01/13 19:10:30 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               생성자 (CONSTRUCTORS)                        */
/* ************************************************************************** */

/*
 * ScavTrap::ScavTrap - 기본 생성자
 *
 * 기본값으로 ScavTrap을 생성합니다:
 * - 이름: "default"
 * - 체력: 100
 * - 에너지: 50
 * - 공격 데미지: 20
 */
ScavTrap::ScavTrap(void)
  : ClapTrap("default",
             100,
             50,
             20) {
  std::cout << "ScavTrap default constructor called" << std::endl;
}

/*
 * ScavTrap::ScavTrap - 이름 생성자
 * @name: ScavTrap의 이름
 *
 * 지정된 이름과 ScavTrap 스탯으로 생성합니다.
 */
ScavTrap::ScavTrap(const std::string &name)
  : ClapTrap(name,
             100,
             50,
             20) {
  std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

/*
 * ScavTrap::ScavTrap - 복사 생성자
 * @other: 복사할 ScavTrap 객체
 *
 * 다른 ScavTrap의 모든 속성을 복사하여 새 ScavTrap을 생성합니다.
 */
ScavTrap::ScavTrap(const ScavTrap &other)
  : ClapTrap(other) {
  std::cout << "ScavTrap copy constructor called" << std::endl;
  *this = other;
}

/*
 * ScavTrap::operator= - 복사 대입 연산자
 * @other: 할당할 ScavTrap 객체
 *
 * 다른 ScavTrap의 속성을 이 ScavTrap에 할당합니다.
 *
 * Return: 연쇄 할당을 위한 이 객체의 참조
 */
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap copy assignment operator called" << std::endl;
  if (this != &other)
    ClapTrap::operator=(other);
  return *this;
}

/*
 * ScavTrap::~ScavTrap - 소멸자
 *
 * ScavTrap을 파괴하고 메시지를 출력합니다.
 */
ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

/* ************************************************************************** */
/*                                  행동 (ACTIONS)                            */
/* ************************************************************************** */

/*
 * ScavTrap::guardGate - Gate keeper 모드 활성화
 *
 * ScavTrap이 Gate keeper 모드로 전환됩니다.
 * 이것은 ScavTrap 전용 특수 능력입니다.
 */
void ScavTrap::guardGate(void) {
  std::cout << _classTag() << " " << _name << " is now in Gate keeper mode"
            << std::endl;
}

/* ************************************************************************** */
/*                          헬퍼 함수 (PROTECTED HELPERS)                     */
/* ************************************************************************** */

const std::string ScavTrap::_classTag() const { return "ScavTrap"; }
