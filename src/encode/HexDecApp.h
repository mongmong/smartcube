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

#ifndef HEXDECAPP_H_
#define HEXDECAPP_H_

#include "ConsoleApp.h"

namespace smartcube
{
	class HexDecApp : public ConsoleApp
	{
		public:
			HexDecApp();
			virtual ~HexDecApp();

		protected:
			void defineOptions(Poco::Util::OptionSet& options);

			virtual const std::string getUsage() const;
			virtual const std::string getHeader() const;

		protected:
			int main2(const std::vector<std::string>& args);
	};
}

#endif /* HEXDECAPP_H_ */
