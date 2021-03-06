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

#include <Poco/DynamicAny.h>

#include "Ceil.h"

#include "CeilApp.h"

namespace smartcube
{
	CeilApp::CeilApp()
	{
		// TODO Auto-generated constructor stub

	}

	CeilApp::~CeilApp()
	{
		// TODO Auto-generated destructor stub
	}

	void CeilApp::defineOptions(Poco::Util::OptionSet& options)
	{
		ConsoleApp::defineOptions(options);

		options.addOption(Poco::Util::Option(
				"precision", "p", "specify calculation, precision.").required(
				false).repeatable(false) .argument("precision", true).binding(
				"smartcube.math.ceil.precision"));
	}

	const std::string CeilApp::getUsage() const
	{
		return "[OPTIONS] [-p <precision>] [--] <column> [<column> ...]";
	}

	const std::string CeilApp::getHeader() const
	{
		return "Round columns to smallest double values not less than the original values in specified precision.";
	}

	int CeilApp::main2(const std::vector<std::string>& args)
	{
		std::vector<std::size_t> columns;
		double precision = config().getDouble("smartcube.math.ceil.precision", 1.0);

		std::vector<std::string>::const_iterator iter = args.begin();
		for (; iter != args.end(); ++iter)
		{
			columns.push_back(Poco::DynamicAny(*iter).convert<std::size_t>());
		}

		Ceil ceil(precision, columns);
		ceil.handle(*getInput(), *getOutput());

		return Poco::Util::Application::EXIT_OK;
	}
}

POCO_APP_MAIN(smartcube::CeilApp);
