#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    FragTrap frag;
    FragTrap trap("Roger");
    
    frag.rangedAttack("Roger");
    trap.takeDamage(20);
	trap.beRepaired(80);
    frag.meleeAttack("Roger");
    trap.takeDamage(30);
    trap.beRepaired(10);
    trap.takeDamage(100);
    trap.beRepaired(33);
    
    frag.vaulthunter_dot_exe("Roger");
    frag.vaulthunter_dot_exe("Roger");
    frag.vaulthunter_dot_exe("Roger");
    frag.vaulthunter_dot_exe("Roger");
    frag.vaulthunter_dot_exe("Roger");

	ScavTrap blop;
	ScavTrap blip("Beyonce");

	blop.rangedAttack("Beyonce");
    blip.takeDamage(20);
	blip.beRepaired(80);
    blop.meleeAttack("Beyonce");
    blip.takeDamage(30);
    blip.beRepaired(10);
    blip.takeDamage(100);
    blip.beRepaired(33);

	blip.challengeNewcomer("Gertrude");
	blip.challengeNewcomer("Gertrude");
	blip.challengeNewcomer("Gertrude");

	return (0);
}