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

#ifndef ADD_H_
#define ADD_H_

#include <sys/types.h>

#include "RoutineImpl.h"

namespace smartcube
{
	/*
	class Add : public Routine
	{
		public:
			Add(const std::vector<std::size_t>& columns);
			virtual ~Add();

		public:
			virtual void handle(Input& input, Output& output);

		private:
			std::vector<std::size_t>	_columns;
	};
	*/

	class AddOp
	{
		public:
			inline void operator ()(const Poco::DynamicAny& op1, const Poco::DynamicAny& op2, Poco::DynamicAny& out)
			{
				out = static_cast<double>(op1) + static_cast<double>(op2);
			}
	};

	typedef SimpleRoutineWrapper< Project2To1RoutineImpl<AddOp>, AddOp > Add;
}

#endif /* ADD_H_ */
