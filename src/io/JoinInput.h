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

#ifndef JOININPUT_H_
#define JOININPUT_H_

#include <vector>

#include "Input.h"

namespace smartcube
{
	class JoinInput : public Input
	{
		public:
			JoinInput(std::vector<InputPtr>& inputs);
			virtual ~JoinInput();

		public:
			std::vector<InputPtr>& getInputs();
			virtual RecordPtr pop();

		private:
			std::vector<InputPtr>	_inputs;
	};
}

#endif /* JOININPUT_H_ */
