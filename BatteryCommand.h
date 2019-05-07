/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// BatteryCommand.h

#ifndef _BATTERYCOMMAND_h
#define _BATTERYCOMMAND_h

#include "SerialCommand.h"
#include "BatteryMode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class GetBatteryCmd : public OSerialCommand {
public:
    CommandState Run();
    GetBatteryCmd(char* rsp);
};

#endif

