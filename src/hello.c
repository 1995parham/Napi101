/*
 * In The Name Of God
 * ========================================
 * [] File Name : hello.c
 *
 * [] Creation Date : 08-06-2017
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2017 Parham Alvani.
 */

#include <node_api.h>

void say_hello(napi_env env, napi_callback_info info)
{
	printf("Hello\n");
	return;
}

void init(napi_env env, napi_value exports, napi_value module, void* priv)
{
	napi_status status;
	napi_property_descriptor desc = {
		/*
		 * String describing the key for the property, encoded as UTF8.
		 */
		.utf8name = "hello",
		/*
		 * Set this to make the property descriptor object's value property
		 * to be a JavaScript function represented by method.
		 * If this is passed in, set value, getter and setter to NULL (since these members won't be used).
		 */
		.method = say_hello,
		/*
		 * A function to call when a get access of the property is performed.
		 * If this is passed in, set value and method to NULL (since these members won't be used).
		 * The given function is called implicitly by the runtime when the property is accessed
		 * from JavaScript code (or if a get on the property is performed using a N-API call).
		 */
		.getter = NULL,
		/*
		 * A function to call when a set access of the property is performed.
		 * If this is passed in, set value and method to NULL (since these members won't be used).
		 * The given function is called implicitly by the runtime when the property is set
		 * from JavaScript code (or if a set on the property is performed using a N-API call).
		 */
		.setter = NULL,
		/*
		 * The value that's retrieved by a get access of the property if the property is a data property.
		 * If this is passed in, set getter, setter, method and data to NULL (since these members won't be used).
		 */
		.value = NULL,
		/*
		 * The attributes associated with the particular property. See napi_property_attributes.
		 */
		.attributes = napi_default,
		/*
		 * The callback data passed into method, getter and setter if this function is invoked.
		 */
		.data = NULL
	};
	/*
	 * This method allows the efficient definition of multiple properties on a given object.
	 */
	status = napi_define_properties(env, exports, 1, &desc);
}


NAPI_MODULE(hello, init)
