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

#include "Backfill.h"

#include "BackfillApp.h"

namespace smartcube
{
	BackfillApp::BackfillApp()
	{
	}

	BackfillApp::~BackfillApp()
	{
	}

	void BackfillApp::defineOptions(Poco::Util::OptionSet& options)
	{
		ConsoleApp::defineOptions(options);
	}

	const std::string BackfillApp::getUsage() const
	{
		return "[OPTIONS] [--] <test> <origin> <backfill> [<test> <origin> <backfill> ... ]";
	}

	const std::string BackfillApp::getHeader() const
	{
		return ConsoleApp::getHeader();
	}

	int BackfillApp::main2(const std::vector<std::string>& args)
	{
		std::vector<std::size_t> columns;

		std::vector<std::string>::const_iterator iter = args.begin();
		for (; iter != args.end(); ++iter)
		{
			columns.push_back(Poco::DynamicAny(*iter).convert<std::size_t>());
		}

		Backfill Backfill(columns);
		Backfill.handle(*getInput(), *getOutput());

		return Poco::Util::Application::EXIT_OK;
	}
}

POCO_APP_MAIN(smartcube::BackfillApp);
