/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:08 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/12 13:57:08 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               생성자 (CONSTRUCTORS)                        */
/* ************************************************************************** */

/*
 * FragTrap::FragTrap - 기본 생성자
 *
 * 기본값으로 FragTrap을 생성합니다:
 * - 이름: "default"
 * - 체력: 100
 * - 에너지: 50
 * - 공격 데미지: 20
 */
FragTrap::FragTrap(void)
  : ClapTrap("default",
             100,
             100,
             30) {
  std::cout << "FragTrap default constructor called" << std::endl;
}

/*
 * FragTrap::FragTrap - 이름 생성자
 * @name: FragTrap의 이름
 *
 * 지정된 이름과 FragTrap 스탯으로 생성합니다.
 */
FragTrap::FragTrap(const std::string &name)
  : ClapTrap(name,
             100,
             100,
             30) {
  std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

/*
 * FragTrap::FragTrap - 복사 생성자
 * @other: 복사할 FragTrap 객체
 *
 * 다른 FragTrap의 모든 속성을 복사하여 새 FragTrap을 생성합니다.
 */
FragTrap::FragTrap(const FragTrap &other)
  : ClapTrap(other) {
  std::cout << "FragTrap copy constructor called" << std::endl;
  *this = other;
}

/*
 * FragTrap::operator= - 복사 대입 연산자
 * @other: 할당할 FragTrap 객체
 *
 * 다른 FragTrap의 속성을 이 FragTrap에 할당합니다.
 *
 * Return: 연쇄 할당을 위한 이 객체의 참조
 */
FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap copy assignment operator called" << std::endl;
  if (this != &other)
    ClapTrap::operator=(other);
  return *this;
}

/*
 * FragTrap::~FragTrap - 소멸자
 *
 * FragTrap을 파괴하고 메시지를 출력합니다.
 */
FragTrap::~FragTrap(void) {
  std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

/* ************************************************************************** */
/*                                  행동 (ACTIONS)                            */
/* ************************************************************************** */

/*
 * FragTrap::highFivesGuys - 하이파이브 요청
 *
 * FragTrap이 긍정적인 하이파이브를 요청합니다.
 * 이것은 FragTrap 전용 특수 능력입니다.
 */
void FragTrap::highFivesGuys() const {
  std::cout << _classTag() << " " << _name << " requests a high five! ✋"
            << std::endl;
}

/* ************************************************************************** */
/*                          헬퍼 함수 (PROTECTED HELPERS)                     */
/* ************************************************************************** */

const std::string FragTrap::_classTag() const { return "FragTrap"; }
