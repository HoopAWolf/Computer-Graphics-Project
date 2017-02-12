#include "Application.h"
#include "DetectMemoryLeak.h"

struct AtExit
{
	~AtExit() { _CrtDumpMemoryLeaks(); }
} doAtExit;

int main( void )
{
	Application app;
	app.Init();
	app.Run();
	app.Exit();
}