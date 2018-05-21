﻿#pragma once
#include <cpprest/json.h>

#include <utility>

namespace TwitchXX
{
	///A virtual base for JsonNotNullValueWrapper and JsonNullValueWrapper
	/** An abstract interface class*/
	class JsonValueWrapper
	{
	public:
		virtual ~JsonValueWrapper() = default;

		virtual std::string as_string() const = 0;          ///< String representation
		virtual int as_integer() const = 0;                 ///< Integer representation
		virtual bool as_bool() const = 0;                   ///< Booleam representation                                          representation
		virtual double as_double() const = 0;               ///< Double representation
		virtual web::json::number as_number() const = 0;    ///< web::Json::number representation
		virtual unsigned int as_uint() const = 0;           ///< Unsigned int representation
		virtual unsigned long long as_ulong() const = 0;    ///< Unsigned long long representation

		///@{
		/* Type casting method for auto resolving JsonValue */
		operator std::string() const { return as_string(); };
		operator int() const { return as_integer(); };
		operator bool() const { return as_bool(); };
		operator double() const { return as_double(); }
		operator web::json::number() const { return as_number();}
		operator unsigned int() const { return as_uint(); }
		operator unsigned long long() const { return as_ulong(); }
		///@}

	};
	//A web::json::value objects
	/**
	* A class representin an actual web::json::value object.
	*/
	class JsonNotNullValueWrapper : public JsonValueWrapper
	{
	public:
		///Wrapping up web::json::value object
		explicit JsonNotNullValueWrapper(web::json::value value) : _json(std::move(value)) {};
		///Must always wrap some existing object
		JsonNotNullValueWrapper() = delete;

		///@{
		/** Basic type getters for stub-object.
		* These methods doesn't get the actual value type of underlying, so it's still can throw. (It's intentional. To prevent implicit type conversions e.t.c).
		*/
		std::string as_string() const override
		{ return _json.as_string(); }

		int as_integer() const override
		{ return _json.as_integer(); }

		bool as_bool() const override
		{ return _json.as_bool(); }

		double as_double() const override
		{ return  _json.as_double(); }

		web::json::number as_number() const override
		{ return  _json.as_number(); }

		unsigned int as_uint() const override
		{
			return _json.is_string() ?
				  		_json.as_string().empty() ?
							0
						: static_cast<unsigned int>(std::stoul(_json.as_string()))
				   : _json.as_number().to_uint32();
		}

		unsigned long long as_ulong() const override
		{
			return _json.is_string() ?
				 	_json.as_string().empty() ?
					 0 : static_cast<uint64_t>(std::stoll(_json.as_string()))
				   : _json.as_number().to_uint64();
		}
		///@}

	private:
		web::json::value _json;
	};

	/// web::json::value wrapper for non-existing elements.
	/**
	* Used as a stub, to get a default value of any requested type, if such element is not present in some object wrapped by JsonWrapper class object.
	*/
	class JsonNullValueWrapper: public JsonValueWrapper
	{
	public:
        ///@{
        /* For JsonNullValueWrapper these methods always return default values */
        std::string        as_string() const override { return std::string(); };
		int 			   as_integer() const override { return 0; };
		bool 			   as_bool() const override { return false; }
		double 			   as_double() const override { return 0; };
		web::json::number  as_number() const override { return web::json::value(0).as_number(); };
		unsigned int 	   as_uint() const override { return 0; }
		unsigned long long as_ulong() const override { return 0; }
        ///@}
	};

	/// web::json::value::object wrapper class
	/** 
	* Can be used to wrap up web::json::value::object objects to access thier elemets without a chance to get an exception, 
	* if there is no such request element present. If key is present it returns its value, or default value otherwise.
	*/
	class JsonWrapper
	{
	public:
		///Constructor.
		explicit JsonWrapper(web::json::value value) : _json(std::move(value)) {}
		///Cannot be empty, must wrap some json object.
		JsonWrapper() = delete; 

		/// Accessing the values of keys
		/** If key exist for current json object returns JsonNotNullValueWrapper object, and if it does not - JsonNullVAlueWrapper one.*/
		std::unique_ptr<JsonValueWrapper> operator[] (const std::string& param)
		{
			if (param_exist(param)) 
				return std::make_unique<JsonNotNullValueWrapper>(_json[param]);
			return std::make_unique<JsonNullValueWrapper>();
		}

	private:
		web::json::value _json;

		bool param_exist(const std::string & param) { return _json.has_field(param) && !_json[param].is_null(); };
	};
	
}
