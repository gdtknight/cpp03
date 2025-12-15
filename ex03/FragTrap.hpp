/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:25:40 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/14 21:25:40 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/*
 * FragTrap - ClapTrap의 파생 클래스
 *
 * FragTrap은 특수 능력을 가진 ClapTrap의 또 다른 버전입니다:
 * - 체력: 100
 * - 에너지: 100 (주의: ex02에서는 50이었으나 ex03에서는 100)
 * - 공격 데미지: 30
 *
 * virtual 상속:
 * - DiamondTrap에서 다이아몬드 상속 문제를 해결하기 위해 virtual 상속 사용
 *
 * 특수 능력:
 * - highFivesGuys(): 긍정적인 하이파이브 요청
 */
class FragTrap : virtual public ClapTrap {
  public:
  /* 생성자 & 소멸자 */
  FragTrap(void);  /* 기본 생성자 */
  FragTrap(const std::string &name);  /* 이름 생성자 */
  FragTrap(const FragTrap &other);  /* 복사 생성자 */
  
  /* 대입 연산자 */
  FragTrap &operator=(const FragTrap &other);
  
  /* 소멸자 */
  ~FragTrap(void);

  /* FragTrap 전용 특수 능력 */
  void highFivesGuys(void) const;
};

#endif
