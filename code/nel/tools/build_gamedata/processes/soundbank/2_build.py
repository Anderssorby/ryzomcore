#!/usr/bin/python
# 
# \file 2_build.py
# \brief Build soundbank
# \date 2009-06-03 10:47GMT
# \author Jan Boon (Kaetemi)
# Python port of game data build pipeline.
# Build soundbank
# 
# NeL - MMORPG Framework <http://dev.ryzom.com/projects/nel/>
# Copyright (C) 2009-2014  by authors
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
# 

import time, sys, os, shutil, subprocess, distutils.dir_util
sys.path.append("../../configuration")

if os.path.isfile("log.log"):
	os.remove("log.log")
log = open("log.log", "w")
from scripts import *
from buildsite import *
from process import *
from tools import *
from directories import *

printLog(log, "")
printLog(log, "-------")
printLog(log, "--- Build soundbank")
printLog(log, "-------")
printLog(log, time.strftime("%Y-%m-%d %H:%MGMT", time.gmtime(time.time())))
printLog(log, "")

# Find tools
BuildSoundbank = findTool(log, ToolDirectories, BuildSoundbankTool, ToolSuffix)
printLog(log, "")

# build_soundbank  <leveldesign> <dfn> <build_packed_sheets>
printLog(log, ">>> Build soundbank <<<")
if BuildSoundbank == "":
	toolLogFail(log, BuildSoundbankTool, ToolSuffix)
else:
	mkPath(log, SoundDirectory)
	mkPath(log, SoundDfnDirectory)
	mkPath(log, ExportBuildDirectory + "/" + SoundSheetsBuildDirectory)
	subprocess.call([ BuildSoundbank, SoundDirectory, SoundDfnDirectory, ExportBuildDirectory + "/" + SoundSheetsBuildDirectory ])
printLog(log, "")

log.close()


# end of file