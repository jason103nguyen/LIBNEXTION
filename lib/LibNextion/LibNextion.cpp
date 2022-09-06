#ifndef LIB_NEXTION_H
#define LIB_NEXTION_H

#include "LibNextion.h"

/*
 * Send command to Nextion.
 *
 * @param cmd - the string of command.
 */
void sendCommand(const char* cmd)
{
    while (nexSerial.available())
    {
        nexSerial.read();
    }
    
    nexSerial.print(cmd);
    nexSerial.write(0xFF);
    nexSerial.write(0xFF);
    nexSerial.write(0xFF);
}

#endif
