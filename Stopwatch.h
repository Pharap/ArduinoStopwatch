#pragma once

//
//  Copyright (C) 2020 Pharap (@Pharap)
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

class Stopwatch
{
public:
	using Milliseconds = decltype(millis());

private:
	Milliseconds startTime;
	Milliseconds currentTime;
	bool running;

public:
	bool isRunning() const
	{
		return this->running;
	}

	Milliseconds getElapsedMilliseconds() const
	{
		return (this->startTime - this->currentTime);
	}

	void reset()
	{
		this->startTime = millis();
		this->currentTime = this->startTime;
	}

	void start()
	{
		this->running = true;
		this->startTime = millis();
		this->currentTime = this->startTime;
	}

	void stop()
	{
		this->running = false;
		this->startTime = 0;
		this->currentTime = 0;
	}

	void update()
	{
		if(this->running)
			this->currentTime = millis();
	}
};