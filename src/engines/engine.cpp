/* eos - A reimplementation of BioWare's Aurora engine
 * Copyright (c) 2010 Sven Hesse (DrMcCoy), Matthew Hoops (clone2727)
 *
 * The Infinity, Aurora, Odyssey and Eclipse engines, Copyright (c) BioWare corp.
 * The Electron engine, Copyright (c) Obsidian Entertainment and BioWare corp.
 *
 * This file is part of eos and is distributed under the terms of
 * the GNU General Public Licence. See COPYING for more informations.
 */

/** @file engines/engine.cpp
 *  Generic engine interface
 */

#include "engines/engine.h"

#include "common/util.h"
#include "common/stream.h"
#include "common/file.h"

#include "aurora/resman.h"
#include "aurora/error.h"

namespace Engines {

Engine::Engine() {
}

Engine::~Engine() {
}

void Engine::indexMandatoryKEY(const std::string &key) {
	Common::SeekableReadStream *keyFile = ResMan.getKEYList().openFile(key, true);
	if (!keyFile)
		throw Common::Exception("No such KEY");

	try {
		ResMan.loadKEY(*keyFile);
	} catch(...) {
		delete keyFile;
		throw;
	}

	delete keyFile;
}

void Engine::indexOptionalKEY(const std::string &key) {
	Common::SeekableReadStream *keyFile = ResMan.getKEYList().openFile(key, true);
	if (!keyFile)
		return;

	try {
		ResMan.loadKEY(*keyFile);
	} catch(...) {
		delete keyFile;
		throw;
	}

	delete keyFile;
}

void Engine::dumpStream(Common::SeekableReadStream &stream, const std::string &fileName) {
	uint32 pos = stream.pos();

	stream.seek(0);

	Common::DumpFile file;
	if (!file.open(fileName)) {
		stream.seek(pos);
		return;
	}

	file.writeStream(stream);
	file.close();

	stream.seek(pos);
}

} // End of namespace Engine
