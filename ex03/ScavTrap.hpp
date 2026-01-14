/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:06 by yoshin            #+#    #+#             */
/*   Updated: 2026/01/13 19:09:30 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*
 * ScavTrap - ClapTrap의 파생 클래스
 *
 * ScavTrap은 향상된 스탯을 가진 ClapTrap의 업그레이드 버전입니다:
 * - 체력: 100 (기본 10에서 증가)
 * - 에너지: 50 (기본 10에서 증가)
 * - 공격 데미지: 20 (기본 0에서 증가)
 *
 * 특수 능력:
 * - attack(): ClapTrap의 attack을 오버라이드
 * - guardGate(): Gate keeper 모드 활성화
 */
class ScavTrap : virtual public ClapTrap {
  public:
  /* 생성자 & 소멸자 */
  ScavTrap(void);                    /* 기본 생성자 */
  ScavTrap(const std::string &name); /* 이름 생성자 */
  ScavTrap(const ScavTrap &other);   /* 복사 생성자 */

  /* 대입 연산자 */
  ScavTrap &operator=(const ScavTrap &other);

  /* 소멸자 */
  ~ScavTrap(void);

  /* ScavTrap 전용 특수 능력 */
  void attack(const std::string &target);
  void guardGate(void);

  protected:
  virtual const char *_classTag(void) const;
};
#endif
