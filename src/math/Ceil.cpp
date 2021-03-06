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

#include <math.h>

#include "Ceil.h"

namespace smartcube
{
	Ceil::Ceil(double precision, const std::vector<std::size_t>& columns) :
		_precision(precision), _columns(columns)
	{
		// TODO Auto-generated constructor stub
	}

	Ceil::~Ceil()
	{
		// TODO Auto-generated destructor stub
	}

	void Ceil::handle(Input& input, Output& output)
	{
		RecordPtr rec = input.pop();

		for (; !rec->eof(); output.push(rec), rec = input.pop())
		{
			std::size_t s = rec->size();
			rec->resize(s + _columns.size());

			std::vector<std::size_t>::iterator iter = _columns.begin();
			for (; iter != _columns.end(); ++iter)
			{
				std::size_t index = s + iter - _columns.begin();
				Cell& any = (*rec)[*iter];

				(*rec)[index] = ceil(static_cast<double> (any) / _precision)
						* _precision;
			}
		}
	}
}
