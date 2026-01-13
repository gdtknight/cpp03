/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:13:24 by yoshin            #+#    #+#             */
/*   Updated: 2026/01/13 19:07:55 by yoshin           ###   ########.fr       */
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
 * ClapTrap::~ClapTrap - 소멸자
 *
 * ClapTrap을 파괴하고 메시지를 출력합니다.
 */
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
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
 * ClapTrap::ClapTrap - 확장 생성자 (파생 클래스용)
 * @name: ClapTrap의 이름
 * @hitPoints: 초기 체력
 * @energyPoints: 초기 에너지
 * @attackDamage: 공격 데미지
 *
 * 커스텀 스탯으로 ClapTrap을 생성합니다.
 * 주로 파생 클래스(ScavTrap, FragTrap 등)에서 사용됩니다.
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

/* ************************************************************************** */
/*                                  행동 (ACTIONS)                            */
/* ************************************************************************** */

/*
 * ClapTrap::attack - 대상 공격
 * @target: 공격할 대상의 이름
 *
 * ClapTrap이 대상을 공격하여 _attackDamage만큼 데미지를 줍니다.
 * 1 에너지 포인트를 소모합니다.
 * 체력이 0이거나 에너지가 없으면 공격할 수 없습니다.
 */
void ClapTrap::attack(const std::string &target) {
  if (!_canPerform(ATTACK))
    return;

  --_energyPoints;

  std::cout << _classTag() << " " << _name << " attacks " << target
            << ", causing " << _attackDamage << " points of damage!"
            << std::endl;
}

/*
 * ClapTrap::takeDamage - 데미지 받기
 * @amount: 받을 데미지 양
 *
 * ClapTrap이 데미지를 받습니다.
 * 받은 데미지가 현재 체력보다 크면 체력은 0이 됩니다.
 * 이미 죽은 경우(체력 0) 추가 데미지를 받을 수 없습니다.
 */
void ClapTrap::takeDamage(unsigned int amount) {
  if (!_canPerform(TAKE_DAMAGE))
    return;

  _hitPoints = (amount >= _hitPoints) ? 0 : _hitPoints - amount;

  std::cout << _classTag() << " " << _name << " takes " << amount
            << " points of damage!" << std::endl
            << "Hit points: " << _hitPoints << std::endl;
}

/*
 * ClapTrap::beRepaired - 체력 회복
 * @amount: 회복할 체력 양
 *
 * ClapTrap이 스스로를 수리하여 체력을 회복합니다.
 * 1 에너지 포인트를 소모합니다.
 * 체력이 0이거나 에너지가 없으면 수리할 수 없습니다.
 */
void ClapTrap::beRepaired(unsigned int amount) {
  if (!_canPerform(REPAIR))
    return;

  --_energyPoints;
  _hitPoints += amount;

  std::cout << _classTag() << " " << _name << " is repaired for " << amount
            << " points!" << std::endl
            << "Hit points: " << _hitPoints << std::endl;
}

/* ************************************************************************** */
/*                           PRIVATE 헬퍼 (PRIVATE HELPERS)                  */
/* ************************************************************************** */

/*
 * ClapTrap::_getActionStr - 행동 enum을 문자열로 변환
 * @action: 변환할 Action enum 값
 *
 * 오류 메시지용 행동 문자열을 반환합니다.
 *
 * Return: 행동을 나타내는 문자열
 */
const char *ClapTrap::_getActionStr(Action action) {
  switch (action) {
  case ATTACK:
    return ("attack");
  case REPAIR:
    return ("be repaired");
  case TAKE_DAMAGE:
    return ("take damage");
  }

  return "unknown action";
}

/**
 * @brief 클래스 식별 문자열을 반환합니다.
 *
 * 현재 객체의 클래스 이름을 나타내는 문자열을 반환합니다.
 * 주로 공통 로직에서 클래스별 메시지를 출력하기 위해 사용됩니다.
 *
 * 파생 클래스에서는 이 함수를 오버라이드하여
 * 각 클래스에 맞는 식별 문자열을 제공할 수 있습니다.
 *
 * @return
 * 클래스 이름을 나타내는 문자열 리터럴
 */
const char *ClapTrap::_classTag(void) const { return ("ClapTrap"); }

/*
 * ClapTrap::_canPerform - 행동 수행 가능 여부 확인
 * @action: 확인할 행동
 *
 * ClapTrap이 주어진 행동을 수행할 수 있는지 확인합니다.
 * 조건:
 * - 체력이 0보다 커야 함
 * - TAKE_DAMAGE가 아닌 행동은 에너지가 필요함
 *
 * Return: 행동 가능하면 true, 아니면 false
 */
bool        ClapTrap::_canPerform(Action action) const {
  const bool noHp = (_hitPoints == 0);
  const bool noEp = ((action != TAKE_DAMAGE) && _energyPoints == 0);

  if (noHp || noEp) {
    _printCannotAct(action);
    return false;
  }
  return true;
}

/*
 * ClapTrap::_printCannotAct - 행동 불가 메시지 출력
 * @action: 수행할 수 없는 행동
 *
 * ClapTrap이 행동을 수행할 수 없는 이유를 출력합니다.
 * (죽었거나 에너지가 없음)
 */
void ClapTrap::_printCannotAct(Action action) const {
  if (_hitPoints == 0) {
    std::cout << _classTag() << " " << _name << " cannot "
              << _getActionStr(action) << " (It is dead)" << std::endl;
  } else {
    std::cout << _classTag() << " " << _name << " cannot "
              << _getActionStr(action) << " (No energy points left)"
              << std::endl;
  }
}
