/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:33:24 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/14 19:50:13 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

/*
 * ClapTrap - 기본 로봇 클래스
 *
 * 기본 스탯:
 * - 체력(Hit points): 10
 * - 에너지 포인트(Energy points): 10
 * - 공격 데미지(Attack damage): 0
 *
 * 행동:
 * - attack(): 대상 공격 (에너지 1 소모)
 * - takeDamage(): 피해 입기
 * - beRepaired(): 체력 회복 (에너지 1 소모)
 * - status(): 현재 상태 출력
 */
class ClapTrap {
  public:
  /* 생성자 & 소멸자 */
  ClapTrap(void);  /* 기본 생성자 */
  ClapTrap(const std::string &name);  /* 이름 생성자 */
  ClapTrap(const ClapTrap &other);  /* 복사 생성자 */
  ClapTrap(const std::string &name,
           unsigned int       hitPoints,
           unsigned int       energyPoints,
           unsigned int       attackDamage);  /* 파생 클래스용 확장 생성자 */
  ~ClapTrap(void);  /* 소멸자 */

  /* 대입 연산자 */
  ClapTrap &operator=(const ClapTrap &other);

  /* 행동 메서드 */
  void      attack(const std::string &target);  /* 공격 */
  void      takeDamage(unsigned int amount);  /* 피해 입기 */
  void      beRepaired(unsigned int amount);  /* 수리 */
  void      status(void);  /* 상태 출력 */

  protected:
  /* 멤버 변수 */
  std::string  _name;  /* 이름 */
  unsigned int _hitPoints;  /* 체력 */
  unsigned int _energyPoints;  /* 에너지 포인트 */
  unsigned int _attackDamage;  /* 공격 데미지 */

  /* 행동 타입 열거형 */
  enum Action { ATTACK, REPAIR, TAKE_DAMAGE };

  /* 헬퍼 함수 */
  bool        _canPerform(Action action) const;  /* 행동 가능 여부 확인 */
  void        _printCannotAct(Action action) const;  /* 행동 불가 메시지 출력 */
  std::string _getActionStr(Action action) const;  /* 행동 이름 문자열 반환 */
};

#endif
