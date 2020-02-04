#include <mathlink.h>
#include <wiringPi.h>
#include <mcp3004.h>
#define BASE 100
#define SPI_CHAN 0

int main (int argc, char *argv[])
{
	mcp3004Setup(BASE, SPI_CHAN);
	return MLMain(argc, argv);
}

int mcp3008(int channel){
        return analogRead(BASE+channel);
}

