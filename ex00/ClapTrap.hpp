/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:33:24 by yoshin            #+#    #+#             */
/*   Updated: 2026/01/13 19:06:50 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

/*
 * ClapTrap - 기본 로봇 전투 유닛을 나타내는 클래스
 *
 * 이 클래스는 다음을 가진 기본 로봇을 모델링합니다:
 * - 체력 포인트 (Hit Points)
 * - 에너지 포인트 (Energy Points) - 행동에 필요
 * - 공격 데미지 (Attack Damage)
 *
 * 행동:
 * - attack(): 대상 공격 (1 에너지 소모)
 * - takeDamage(): 데미지를 받음
 * - beRepaired(): 체력 회복 (1 에너지 소모)
 *
 * 상속을 위한 기반 클래스로 설계됨 (ScavTrap, FragTrap 등).
 */
class ClapTrap {
  public:
  /* 생성자 & 소멸자 */
  ClapTrap(void);                    /* 기본 생성자 */
  ClapTrap(const std::string &name); /* 이름 생성자 */
  ClapTrap(const ClapTrap &other);   /* 복사 생성자 */

  /* 파생 클래스를 위한 protected 생성자 */
  ClapTrap(const std::string &name,
           unsigned int       hitPoints,
           unsigned int       energyPoints,
           unsigned int       attackDamage);

  ~ClapTrap(void); /* 소멸자 */

  /* 복사 대입 연산자 */
  ClapTrap &operator=(const ClapTrap &other);

  /* 행동 */
  void      attack(const std::string &target); /* 대상 공격 */
  void      takeDamage(unsigned int amount);   /* 데미지 받기 */
  void      beRepaired(unsigned int amount);   /* 체력 회복 */

  private:
  std::string  _name;                          /* 로봇의 이름 */
  unsigned int _hitPoints;                     /* 현재 체력 (0 = 파괴됨) */
  unsigned int _energyPoints;                  /* 행동을 위한 에너지 */
  unsigned int _attackDamage;                  /* 공격당 데미지 */

  enum Action { ATTACK, REPAIR, TAKE_DAMAGE };

  static const std::string _getActionStr(Action action);
  const std::string        _classTag(void) const;

  bool                     _canPerform(Action action) const;
  void                     _printCannotAct(Action action) const;
};

#endif
