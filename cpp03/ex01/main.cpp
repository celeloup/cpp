#include "FragTrap.hpp"

int main( void )
{
    FragTrap clap;
    FragTrap trap("Michel");
    
    clap.rangedAttack("Michel");
    trap.takeDamage(20);
	trap.beRepaired(80);
    clap.meleeAttack("Michel");
    trap.takeDamage(30);
    trap.beRepaired(10);
    trap.takeDamage(100);
    trap.beRepaired(33);
    
    clap.vaulthunter_dot_exe("Michel");
    clap.vaulthunter_dot_exe("Michel");
    clap.vaulthunter_dot_exe("Michel");
    clap.vaulthunter_dot_exe("Michel");
    clap.vaulthunter_dot_exe("Michel");

	return (0);
}