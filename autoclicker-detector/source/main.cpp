#include "hooks/hooks.hpp"

int main()
{
	printf("Autoclicker Detector 1.0");

	std::thread(Hooks::Spawn).detach();

	return std::cin.get();
}
