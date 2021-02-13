#include "FragTrap.hpp"

int main( void )
{
    FragTrap frag;
    FragTrap trap("Michel");
    
    frag.rangedAttack("Michel");
    trap.takeDamage(20);
	trap.beRepaired(80);
    frag.meleeAttack("Michel");
    trap.takeDamage(30);
    trap.beRepaired(10);
    trap.takeDamage(100);
    trap.beRepaired(33);
    
    frag.vaulthunter_dot_exe("Michel");
    frag.vaulthunter_dot_exe("Michel");
    frag.vaulthunter_dot_exe("Michel");
    frag.vaulthunter_dot_exe("Michel");
    frag.vaulthunter_dot_exe("Michel");

	return (0);
}