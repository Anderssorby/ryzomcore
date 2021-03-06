/**
 * \file patch_object.h
 * \brief CPatchObject
 * \date 2012-08-22 08:58GMT
 * \author Jan Boon (Kaetemi)
 * CPatchObject
 */

/*
 * Copyright (C) 2012  by authors
 *
 * This file is part of RYZOM CORE PIPELINE.
 * RYZOM CORE PIPELINE is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Affero General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * RYZOM CORE PIPELINE is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with RYZOM CORE PIPELINE.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef PIPELINE_PATCH_OBJECT_H
#define PIPELINE_PATCH_OBJECT_H
#include <nel/misc/types_nl.h>

// STL includes

// NeL includes

// Project includes
#include "geom_object.h"

/// Must be passed to the parse and build functions by
/// inheriting classes to parse the actual patch object.
#define PMB_PATCH_OBJECT_PARSE_FILTER 0x2a611c9

namespace PIPELINE {
namespace MAX {
namespace BUILTIN {

/**
 * \brief CPatchObject
 * \date 2012-08-22 08:58GMT
 * \author Jan Boon (Kaetemi)
 * CPatchObject
 */
class CPatchObject : public CGeomObject
{
public:
	CPatchObject(CScene *scene);
	virtual ~CPatchObject();

	// class desc
	static const ucstring DisplayName;
	static const char *InternalName;
	static const NLMISC::CClassId ClassId;
	static const TSClassId SuperClassId;

	// inherited
	virtual void parse(uint16 version, uint filter = 0);
	virtual void clean();
	virtual void build(uint16 version, uint filter = 0);
	virtual void disown();
	virtual void init();
	virtual bool inherits(const NLMISC::CClassId classId) const;
	virtual const ISceneClassDesc *classDesc() const;
	virtual void toStringLocal(std::ostream &ostream, const std::string &pad = "", uint filter = 0) const;

protected:
	// inherited
	virtual IStorageObject *createChunkById(uint16 id, bool container);

}; /* class CPatchObject */

typedef CSceneClassDesc<CPatchObject> CPatchObjectClassDesc;
extern const CPatchObjectClassDesc PatchObjectClassDesc;

} /* namespace BUILTIN */
} /* namespace MAX */
} /* namespace PIPELINE */

#endif /* #ifndef PIPELINE_PATCH_OBJECT_H */

/* end of file */
