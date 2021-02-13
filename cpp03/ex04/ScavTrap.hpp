/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celeloup <celeloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:11:04 by celeloup          #+#    #+#             */
/*   Updated: 2021/01/12 21:46:25 by celeloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap{

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap();
	ScavTrap	& operator=(ScavTrap const & src);

	void challengeNewcomer(std::string const & target);

	void danceChallenge(std::string const & target);
	void singingChallenge(std::string const & target);
	void flipChallenge(std::string const & target);
	void riddleChallenge(std::string const & target);
	void shifumiChallenge(std::string const & target);
private:
	void initialisation();

};

#endif