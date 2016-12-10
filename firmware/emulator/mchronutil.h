//*****************************************************************************
// Filename : 'mchronutil.h'
// Title    : Definitions for mchron utility routines
//*****************************************************************************

#ifndef MCHRONUTIL_H
#define MCHRONUTIL_H

#include "interpreter.h"
#include "controller.h"

// The coredump origin types
#define ORIGIN_GLCD	0
#define ORIGIN_CTRL	1
#define ORIGIN_EEPROM	2

// The active alarm type
#define ALM_MONOCHRON	0
#define ALM_EMUCHRON	1

// Definition of a structure to hold the main() arguments
typedef struct _emuArgcArgv_t
{
  int argDebug;				// argv index for logfile arg
  int argGlutGeometry;			// argv index for glut geometry arg
  int argGlutPosition;			// argv index for glut window pos arg
  int argLcdType;			// argv index for lcd device arg
  int argTty;				// argv index for ncurses tty arg
  ctrlDeviceArgs_t ctrlDeviceArgs;	// Processed args for lcd stub interface
} emuArgcArgv_t;

// mchron command argument translation functions
u08 emuColorGet(char colorId);
u08 emuFontGet(char *fontName);
u08 emuOrientationGet(char orientationId);
int emuStartModeGet(char startId);

// mchron environment functions
int emuArgcArgvGet(int argc, char *argv[]);
void emuCoreDump(u08 origin, const char *location, int arg1, int arg2,
  int arg3, int arg4);
void emuSigSetup(void);
void emuWinClose(void);

// mchron interpreter command line/list functions
int emuLineExecute(cmdLine_t *cmdLine, cmdInput_t *cmdInput);
int emuListExecute(cmdLine_t *cmdLineRoot, char *source);

// mchron interpreter support functions
void emuClockRelease(int echoCmd);
void emuClockUpdate(void);
void emuTimePrint(int type);
void emuTimeSync(void);

// mchron logfile functions
void emuLogfileClose(void);
void emuLogfileOpen(char debugFile[]);
#endif
