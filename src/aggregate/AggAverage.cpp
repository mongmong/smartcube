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

#include "AggAverage.h"

namespace smartcube
{
	AggAverage::AggAverage(std::size_t group, bool showAll, const std::vector<
			std::size_t>& columns) :
		_groupBy(group), _showAll(showAll), _columns(columns)
	{
		// TODO Auto-generated constructor stub
	}

	AggAverage::~AggAverage()
	{
		// TODO Auto-generated destructor stub
	}

	void AggAverage::handle(Input& input, Output& output)
	{
		typedef std::vector<double> AggAverageType;
		AggAverageType sums;
		AggAverageType avgs;
		sums.resize(_columns.size());
		avgs.resize(_columns.size());

		RecordPtr previous = input.pop();
		if (previous->eof())
		{
			return;
		}

		std::vector<std::size_t>::iterator coit = _columns.begin();
		for (; coit != _columns.end(); ++coit)
		{
			std::size_t i = coit - _columns.begin();
			avgs[i] = sums[i] = static_cast<double> ((*previous)[*coit]);
		}

		long count = 1;
		std::size_t index = 0;

		RecordPtr current = input.pop();
		for (; !current->eof(); previous = current, current = input.pop())
		{
			int same = true;
			for (index = 0; index < _groupBy; ++index)
			{
				if ((*current)[index] != (*previous)[index])
				{
					same = false;
					break;
				}
			}

			if (_showAll || !same)
			{
				size_t i = 0;
				for (; i < _columns.size(); ++i)
				{
					avgs[i] = sums[i] / count;
				}
				previous->insert(previous->end(), avgs.begin(), avgs.end());
				output.push(previous);
			}

			if (!same)
			{
				count = 1;

				std::vector<std::size_t>::iterator coit = _columns.begin();
				for (; coit != _columns.end(); ++coit)
				{
					std::size_t i = coit - _columns.begin();
					avgs[i] = sums[i]
							= static_cast<double> ((*previous)[*coit]);
				}
			}
			else
			{
				count++;

				std::vector<std::size_t>::iterator coit = _columns.begin();
				for (; coit != _columns.end(); ++coit)
				{
					std::size_t i = coit - _columns.begin();
					sums[i] += static_cast<double> ((*current)[*coit]);
				}
			}
		}

		size_t i = 0;
		for (; i < _columns.size(); ++i)
		{
			avgs[i] = sums[i] / count;
		}
		previous->insert(previous->end(), avgs.begin(), avgs.end());
		output.push(previous);
	}
}
