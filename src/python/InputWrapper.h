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

#ifndef INPUTWRAPPER_H_
#define INPUTWRAPPER_H_

#include <iostream>

#include <boost/python.hpp>

#include "RecordHelper.h"

#include "Input.h"
#include "DummyInput.h"

namespace smartcube
{
	namespace python = boost::python;

	class InputWrapper: public Input
	{
		public:
			InputWrapper();
			InputWrapper(Input& input);
			virtual ~InputWrapper();

		public:
			void wrap(Input& input);

			inline RecordPtr pop()
			{
				return _input->pop();
			}
			inline python::object pop2()
			{
				// std::cout << "InputWrapper::pop2() called." << std::endl;
				return RecordHelper::recordToPythonList(_input->pop());
			}

		private:
			DummyInput _dummyInput;
			Input* _input;
	};
}

#endif /* INPUTWRAPPER_H_ */