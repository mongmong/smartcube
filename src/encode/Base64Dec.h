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

#ifndef BASE64DEC_H_
#define BASE64DEC_H_

#include <sstream>

#include <Poco/DynamicAny.h>
#include <Poco/Base64Decoder.h>

#include "RoutineImpl.h"

namespace smartcube
{
	class Base64DecOp
	{
		public:
			inline void operator()(const Cell& op,
					Cell& out)
			{
				std::istringstream iss(static_cast<const std::string&> (op));
				Poco::Base64Decoder dec(iss);
				std::string str;
				std::getline(dec, str);

				out = str;
			}
	};

	typedef SimpleRoutineWrapper<Project1To1RoutineImpl<Base64DecOp> ,
			Base64DecOp> Base64Dec;
}

#endif /* BASE64DEC_H_ */
