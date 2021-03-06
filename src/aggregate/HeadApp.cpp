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

#include "Head.h"

#include "HeadApp.h"

namespace smartcube
{
	HeadApp::HeadApp()
	{
		// TODO Auto-generated constructor stub

	}

	HeadApp::~HeadApp()
	{
		// TODO Auto-generated destructor stub
	}

	void HeadApp::defineOptions(Poco::Util::OptionSet& options)
	{
		ConsoleApp::defineOptions(options);

		options.addOption(Poco::Util::Option(
				"groupby", "g", "specify group columns.").required(
				false).repeatable(false) .argument("group", true).binding(
				"smartcube.agg.head.groupby"));

		options.addOption(Poco::Util::Option(
				"lines", "n", "specify the number of lines").required(
				false).repeatable(false).argument("num").binding(
				"smartcube.agg.head.lines"));
	}

	const std::string HeadApp::getUsage() const
	{
		return "[OPTIONS] [-g groupby] [-n num] [--]";
	}

	const std::string HeadApp::getHeader() const
	{
		return ConsoleApp::getHeader();
	}

	int HeadApp::main2(const std::vector<std::string>& args)
	{
		std::vector<std::size_t> columns;
		int group = config().getInt("smartcube.agg.head.groupby", 1);
		int showNum = config().getInt("smartcube.agg.head.lines", 1);

		Head head(group, showNum);
		head.handle(*getInput(), *getOutput());

		return Poco::Util::Application::EXIT_OK;
	}
}

POCO_APP_MAIN(smartcube::HeadApp);
