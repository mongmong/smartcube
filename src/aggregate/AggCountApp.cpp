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

#include "AggCount.h"

#include "AggCountApp.h"

namespace smartcube
{
	AggCountApp::AggCountApp()
	{
		// TODO Auto-generated constructor stub

	}

	AggCountApp::~AggCountApp()
	{
		// TODO Auto-generated destructor stub
	}

	void AggCountApp::defineOptions(Poco::Util::OptionSet& options)
	{
		ConsoleApp::defineOptions(options);

		options.addOption(Poco::Util::Option(
				"groupby", "g", "specify group columns.").required(
				false).repeatable(false) .argument("group", true).binding(
				"smartcube.agg.count.groupby"));

		options.addOption(Poco::Util::Option(
				"showall", "a", "show all rows.").required(
				false).repeatable(false).binding(
				"smartcube.agg.count.showall"));
	}

	const std::string AggCountApp::getUsage() const
	{
		return "[OPTIONS] [-g groupby] [-a] [--]";
	}

	const std::string AggCountApp::getHeader() const
	{
		return "Count records by columns, resulting in new column.";
	}

	int AggCountApp::main2(const std::vector<std::string>& args)
	{
		std::vector<std::size_t> columns;
		int group = config().getInt("smartcube.agg.count.groupby", 1);
		bool showall = config().hasOption("smartcube.agg.count.showall");

		AggCount count(group, showall);
		count.handle(*getInput(), *getOutput());

		return Poco::Util::Application::EXIT_OK;
	}
}

POCO_APP_MAIN(smartcube::AggCountApp);
