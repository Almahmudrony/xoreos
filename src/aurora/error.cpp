/* eos - A reimplementation of BioWare's Aurora engine
 * Copyright (c) 2010 Sven Hesse (DrMcCoy), Matthew Hoops (clone2727)
 *
 * The Infinity, Aurora, Odyssey and Eclipse engines, Copyright (c) BioWare corp.
 * The Electron engine, Copyright (c) Obsidian Entertainment and BioWare corp.
 *
 * This file is part of eos and is distributed under the terms of
 * the GNU General Public Licence. See COPYING for more informations.
 */

/** @file aurora/error.cpp
 *  Basic exceptions to throw when handling files used in Bioware's Aurora engine.
 */

#include "aurora/error.h"

namespace Aurora {

const Common::Exception kGFFFieldTypeError("GFF field type does not match the requested type");

const Common::Exception kOpenError("Can't open file");
const Common::Exception kReadError("Read error");
const Common::Exception kSeekError("Seek error");

} // End of namespace Aurora
