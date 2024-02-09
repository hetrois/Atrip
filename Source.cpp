#include<Engine/Atrip/Atrip.h>


int main()
{
	bool active = true;

	while (active)
	{
		EngineBase* e = new Atrip();
		active = e->Run();
		delete e;
	}
}