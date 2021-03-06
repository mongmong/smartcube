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

#ifndef NORM_H_
#define NORM_H_

#include <sys/types.h>

#include "Routine.h"

namespace smartcube
{

	class Norm : public Routine
	{
		public:
			enum NormOption {Max, Average, Sum};
			Norm(NormOption option, const std::vector<std::size_t>& columns);
			virtual ~Norm();

		public:
			virtual void handle(Input& input, Output& output);

		private:
			NormOption					_option;
			std::vector<std::size_t>	_columns;
	};
}

#endif /* NORM_H_ */
