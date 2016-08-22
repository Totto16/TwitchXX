﻿#pragma once
#include "ChannelFeedTest.h"

class UsersTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		_api = std::make_unique<TwitchXX::Api>();
		_channel_name = U("burannah");
	}

	std::unique_ptr<TwitchXX::Api> _api;
	std::wstring _channel_name;
};