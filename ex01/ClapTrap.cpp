/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:13:24 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/15 15:58:24 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               생성자 (CONSTRUCTORS)                        */
/* ************************************************************************** */

/*
 * ClapTrap::ClapTrap - 기본 생성자
 *
 * 기본값으로 ClapTrap을 생성합니다:
 * - 이름: "default"
 * - 체력: 10
 * - 에너지: 10
 * - 공격 데미지: 0
 */
ClapTrap::ClapTrap()
  : _name("default")
  , _hitPoints(10)
  , _energyPoints(10)
  , _attackDamage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

/*
 * ClapTrap::ClapTrap - 이름 생성자
 * @name: ClapTrap의 이름
 *
 * 지정된 이름과 기본 스탯으로 ClapTrap을 생성합니다.
 */
ClapTrap::ClapTrap(const std::string &name)
  : _name(name)
  , _hitPoints(10)
  , _energyPoints(10)
  , _attackDamage(0) {
  std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

/*
 * ClapTrap::ClapTrap - 확장 생성자 (파생 클래스용)
 * @name: 이름
 * @hitPoints: 체력
 * @energyPoints: 에너지 포인트
 * @attackDamage: 공격 데미지
 *
 * 모든 스탯을 지정하여 ClapTrap을 생성합니다.
 * 주로 파생 클래스에서 사용됩니다.
 */
ClapTrap::ClapTrap(const std::string &name,
                   unsigned int       hitPoints,
                   unsigned int       energyPoints,
                   unsigned int       attackDamage)
  : _name(name)
  , _hitPoints(hitPoints)
  , _energyPoints(energyPoints)
  , _attackDamage(attackDamage) {
  std::cout << "ClapTrap " << _name << " extended constructor called"
            << std::endl;
}

/*
 * ClapTrap::ClapTrap - 복사 생성자
 * @other: 복사할 ClapTrap 객체
 *
 * 다른 ClapTrap의 모든 속성을 복사하여 새 ClapTrap을 생성합니다.
 */
ClapTrap::ClapTrap(const ClapTrap &other)
  : _name(other._name)
  , _hitPoints(other._hitPoints)
  , _energyPoints(other._energyPoints)
  , _attackDamage(other._attackDamage) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
}

/*
 * ClapTrap::operator= - 복사 대입 연산자
 * @other: 할당할 ClapTrap 객체
 *
 * 다른 ClapTrap의 속성을 이 ClapTrap에 할당합니다.
 *
 * Return: 연쇄 할당을 위한 이 객체의 참조
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    _name         = other._name;
    _hitPoints    = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  std::cout << "ClapTrap copy assignment operator called" << std::endl;
  return *this;
}

/*
 * ClapTrap::~ClapTrap - 소멸자
 *
 * ClapTrap을 파괴하고 메시지를 출력합니다.
 */
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

/* ************************************************************************** */
/*                                  행동 (ACTIONS)                            */
/* ************************************************************************** */

/*
 * ClapTrap::attack - 대상 공격
 * @target: 공격할 대상의 이름
 *
 * ClapTrap이 대상을 공격합니다.
 * 1 에너지 포인트를 소모하며, 에너지가 없거나 죽었을 경우 실패합니다.
 */
void ClapTrap::attack(const std::string &target) {
  if (!_canPerform(ATTACK))
    return;
  --_energyPoints;

  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

/*
 * ClapTrap::beRepaired - 체력 회복
 * @amount: 회복할 체력량
 *
 * ClapTrap이 자신을 수리하여 체력을 회복합니다.
 * 1 에너지 포인트를 소모하며, 에너지가 없거나 죽었을 경우 실패합니다.
 */
void ClapTrap::beRepaired(unsigned int amount) {
  if (!_canPerform(REPAIR))
    return;
  --_energyPoints;
  _hitPoints += amount;

  std::cout << "ClapTrap " << _name << " is repaired for " << amount
            << " points!" << std::endl
            << "Hit points: " << _hitPoints << std::endl;
}

/*
 * ClapTrap::takeDamage - 피해 입기
 * @amount: 받을 피해량
 *
 * ClapTrap이 피해를 입습니다.
 * 체력이 0 이하로 떨어지면 죽은 것으로 처리됩니다.
 */
void ClapTrap::takeDamage(unsigned int amount) {
  if (!_canPerform(TAKE_DAMAGE))
    return;

  _hitPoints = (amount >= _hitPoints) ? 0 : _hitPoints - amount;

  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage!" << std::endl
            << "Hit points: " << _hitPoints << std::endl;
}

/*
 * ClapTrap::status - 현재 상태 출력
 *
 * ClapTrap의 현재 스탯을 모두 출력합니다.
 * (이름, 체력, 에너지, 공격 데미지)
 */
void ClapTrap::status(void) {
  std::cout << "=================================" << std::endl;
  std::cout << "Name         : " << _name << std::endl;
  std::cout << "Hit Points   : " << _hitPoints << std::endl;
  std::cout << "Energy Points: " << _energyPoints << std::endl;
  std::cout << "Attack Damage: " << _attackDamage << std::endl;
  std::cout << "=================================" << std::endl;
}

/* ************************************************************************** */
/*                            헬퍼 함수 (PRIVATE HELPERS)                     */
/* ************************************************************************** */

/*
 * ClapTrap::_getActionStr - 행동 타입을 문자열로 변환
 * @action: 행동 타입
 *
 * 행동 열거형을 읽기 쉬운 문자열로 변환합니다.
 *
 * Return: 행동 이름 문자열
 */
std::string ClapTrap::_getActionStr(Action action) const {
  switch (action) {
  case ATTACK:
    return ("attack");
  case REPAIR:
    return ("be repaired");
    break;
  case TAKE_DAMAGE:
    return ("take damage");
  }
  throw std::runtime_error("Invalid args");
}

/*
 * ClapTrap::_printCannotAct - 행동 불가 메시지 출력
 * @action: 수행하려던 행동
 *
 * ClapTrap이 특정 행동을 수행할 수 없는 이유를 출력합니다.
 * (죽었거나 에너지가 없음)
 */
void ClapTrap::_printCannotAct(Action action) const {
  try {
    if (_hitPoints == 0) {
      std::cout << "ClapTrap " << _name << " cannot " << _getActionStr(action)
                << " (It is dead)" << std::endl;
      return;
    }
    std::cout << "ClapTrap " << _name << " cannot " << _getActionStr(action)
              << " (No energy points left)" << std::endl;
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }
}

/*
 * ClapTrap::_canPerform - 행동 가능 여부 확인
 * @action: 수행하려는 행동
 *
 * ClapTrap이 특정 행동을 수행할 수 있는지 확인합니다.
 * 체력이 0이거나 (TAKE_DAMAGE 제외) 에너지가 0이면 불가능합니다.
 *
 * Return: 수행 가능하면 true, 불가능하면 false
 */
bool ClapTrap::_canPerform(Action action) const {
  if (_hitPoints == 0 || ((action != TAKE_DAMAGE) && _energyPoints == 0)) {
    _printCannotAct(action);
    return false;
  }
  return true;
}
