/*
 * Copyright 2010 Chris Chou <m2chrischou@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Poco/UUIDGenerator.h>

#include "Routine.h"

namespace smartcube
{
	Routine::Routine()
	{
		// TODO Auto-generated constructor stub
		_uuid = Poco::UUIDGenerator().createOne();
	}

	Routine::~Routine()
	{
		// TODO Auto-generated destructor stub
	}

	Poco::UUID Routine::getID() const
	{
		return _uuid;
	}

	/*
	 * Private methods
	 */
	Routine::Routine(const Routine&)
	{
	}

	Routine& Routine::operator =(const Routine&)
	{
		return *this;
	}
}
