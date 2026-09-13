#include <glc2d.h>
#include <stdio.h>
#include "CApplication.h"

int main()
{
	g_app.Init();
	g2_Run();
	g_app.Destroy();

	return 0;
}