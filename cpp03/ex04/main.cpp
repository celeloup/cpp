#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int main( void )
{
    // FragTrap frag;
    // FragTrap trap("Roger");
    
    // frag.rangedAttack("Roger");
    // trap.takeDamage(20);
	// trap.beRepaired(80);
    // frag.meleeAttack("Roger");
    // trap.takeDamage(30);
    // trap.beRepaired(10);
    // trap.takeDamage(100);
    // trap.beRepaired(33);
    
    // frag.vaulthunter_dot_exe("Roger");
    // frag.vaulthunter_dot_exe("Roger");
    // frag.vaulthunter_dot_exe("Roger");
    // frag.vaulthunter_dot_exe("Roger");
    // frag.vaulthunter_dot_exe("Roger");

	// ScavTrap blop;
	// ScavTrap blip("Beyonce");

	// blop.rangedAttack("Beyonce");
    // blip.takeDamage(20);
	// blip.beRepaired(80);
    // blop.meleeAttack("Beyonce");
    // blip.takeDamage(30);
    // blip.beRepaired(10);
    // blip.takeDamage(100);
    // blip.beRepaired(33);

	// blip.challengeNewcomer("Gertrude");
	// blip.challengeNewcomer("Gertrude");
	// blip.challengeNewcomer("Gertrude");

	// NinjaTrap dop;
	// NinjaTrap dip("Lily");
	// dop.rangedAttack("Lily");
    // dip.takeDamage(20);
	// dip.beRepaired(80);
    // dop.meleeAttack("Lily");
    // dip.takeDamage(30);
    // dip.beRepaired(10);
    // dip.takeDamage(100);
    // dip.beRepaired(33);

	// dip.ninjaShoebox(blip);
	// dip.ninjaShoebox(trap);

	FragTrap	frag("James");
	ScavTrap	scav("Jessie");
	NinjaTrap	ninja("Miaouss");
	SuperTrap	super("Super");

	std::cout << std::endl << std::endl;
	super.vaulthunter_dot_exe("Jessie");
	super.rangedAttack("Miaouss");
	super.meleeAttack("James");

	std::cout << std::endl << std::endl;
	super.ninjaShoebox(ninja);
	super.ninjaShoebox(scav);
	super.ninjaShoebox(frag);
	std::cout << std::endl << std::endl;
	return (0);
}