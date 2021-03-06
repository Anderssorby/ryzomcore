// Ryzom - MMORPG Framework <http://dev.ryzom.com/projects/ryzom/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.



#include "stdpch.h"

#include "nel/misc/debug.h"
#include "temp_inventory_mode.h"
// nel
#include "nel/misc/string_conversion.h"

using namespace std;
using namespace NLMISC;

namespace TEMP_INV_MODE
{

	NL_BEGIN_STRING_CONVERSION_TABLE (TInventoryMode)
		NL_STRING_CONVERSION_TABLE_ENTRY(Harvest)
		NL_STRING_CONVERSION_TABLE_ENTRY(Loot)
		NL_STRING_CONVERSION_TABLE_ENTRY(Forage)
		NL_STRING_CONVERSION_TABLE_ENTRY(Quarter)
		NL_STRING_CONVERSION_TABLE_ENTRY(BagFull)
		NL_STRING_CONVERSION_TABLE_ENTRY(Craft)
		NL_STRING_CONVERSION_TABLE_ENTRY(MissionReward)
		NL_STRING_CONVERSION_TABLE_ENTRY(Crystallize)

		NL_STRING_CONVERSION_TABLE_ENTRY(Unknown)
	NL_END_STRING_CONVERSION_TABLE(TInventoryMode, InvModeConversion, Unknown)

	//-----------------------------------------------
	// toInvMode :
	//-----------------------------------------------
	TInventoryMode toInvMode(const std::string &str)
	{
		uint16 nb = InvModeConversion.getNbPairs();
		nlassert( uint16(NbModes+1) == nb );

		return InvModeConversion.fromString(str);
	} // toBrickFamily //


	//-----------------------------------------------
	// toString :
	//-----------------------------------------------
	const std::string &toString(TInventoryMode mode)
	{
		return InvModeConversion.toString(mode);
	} // toString //



}; // TEMP_INV_MODE
