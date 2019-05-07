/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// 
// 
// 

#include "BatteryCommand.h"

CommandState GetBatteryCmd::Run() {
    float voltage = batteryMode.getVoltage();
    memcpy(responseBuffer, &voltage, sizeof voltage);
    return COMMAND_RESPOND;
}

GetBatteryCmd::GetBatteryCmd(char* rsp) {
    responseBuffer = rsp;
}