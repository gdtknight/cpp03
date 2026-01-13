/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:38:11 by yoshin            #+#    #+#             */
/*   Updated: 2025/12/14 19:38:11 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/*
 * DiamondTrap - ScavTrap과 FragTrap의 다중 상속 클래스
 *
 * DiamondTrap은 다이아몬드 상속 문제를 보여줍니다:
 * - ScavTrap과 FragTrap 모두로부터 상속
 * - 두 부모 모두 ClapTrap을 상속 (다이아몬드 형태)
 * - virtual 상속을 사용하여 ClapTrap의 중복 방지
 *
 * 스탯:
 * - 체력: FragTrap에서 상속 (100)
 * - 에너지: ScavTrap에서 상속 (50)
 * - 공격 데미지: FragTrap에서 상속 (30)
 *
 * 특수 능력:
 * - attack(): ScavTrap의 attack 사용
 * - whoAmI(): DiamondTrap 이름과 ClapTrap 이름 표시
 */
class DiamondTrap : public ScavTrap, public FragTrap {
  public:
  /* 생성자 & 소멸자 */
  DiamondTrap(void);                     /* 기본 생성자 */
  DiamondTrap(std::string name);         /* 이름 생성자 */
  DiamondTrap(const DiamondTrap &other); /* 복사 생성자 */

  /* 대입 연산자 */
  DiamondTrap &operator=(const DiamondTrap &other);

  /* 소멸자 */
  ~DiamondTrap(void);

  /* ScavTrap의 attack 메서드 사용 (명시적 지정) */
  using ScavTrap::attack;

  /* DiamondTrap 전용 특수 능력 */
  void whoAmI(void);

  protected:
  virtual const std::string _classTag(void) const;

  private:
  /* DiamondTrap 자신의 이름 (ClapTrap::_name과 별도) */
  std::string _name;
};

#endif
