﻿#pragma once
#include <gtest/gtest.h>
#include <TwitchXX.h>
#include <cpprest/details/basic_types.h>


class TeamsTest: public ::testing::Test
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
