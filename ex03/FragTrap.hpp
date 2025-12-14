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

class FragTrap : virtual public ClapTrap {
  public:
  FragTrap(void);
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  FragTrap &operator=(const FragTrap &other);
  ~FragTrap(void);

  void highFivesGuys(void) const;
};

#endif
