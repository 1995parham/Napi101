/*
 * In The Name Of God
 * ========================================
 * [] File Name : bye.c
 *
 * [] Creation Date : 09-06-2017
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2017 Parham Alvani.
 */

#include <node_api.h>
#include <stdio.h>
#include <unistd.h>

napi_value bye_sync(napi_env env, napi_callback_info info)
{
	napi_value retval;

	printf("Hello sync\n");
	sleep(1);
	printf("Bye sync\n");

	napi_create_int64(env, 1373, &retval);

	return retval;
}

void bye_async_execute(napi_env env, void *data)
{
	sleep(1);
	printf("Hello async\n");
}

void bye_async_complete(napi_env env, napi_status status, void* data)
{
	printf("Hello completed async\n");
}

napi_value bye_async(napi_env env, napi_callback_info info)
{
	napi_value retval;
	napi_async_work work;
	napi_value async_resource_name;

	/*
	 * napi_status napi_create_async_work(napi_env env,
                                   napi_value async_resource,
                                   napi_value async_resource_name,
                                   napi_async_execute_callback execute,
                                   napi_async_complete_callback complete,
                                   void* data,
                                   napi_async_work* result);
	 * async_resource_name should be a null-terminated, UTF-8-encoded string.
	 * Note: The async_resource_name identifier is provided by the user and should be representative of the type of async work being performed. It is also recommended to apply namespacing to the identifier, e.g. by including the module name.
	 * See the async_hooks documentation for more information.
	 */
	napi_create_string_utf8(env, "bye:sleep", -1, &async_resource_name);
	napi_create_async_work(env, NULL, async_resource_name, bye_async_execute, bye_async_complete, NULL, &work);
	napi_queue_async_work(env, work);

	napi_create_int64(env, 1373, &retval);

	return retval;
}

napi_value init(napi_env env, napi_value exports)
{
	napi_status status;
	napi_property_descriptor desc[] = {
		{
			.utf8name = "byeSync",
			.method = bye_sync,
			.getter = NULL,
			.setter = NULL,
			.value = NULL,
			.attributes = napi_default,
			.data = NULL
		},{
			.utf8name = "byeASync",
			.method = bye_async,
			.getter = NULL,
			.setter = NULL,
			.value = NULL,
			.attributes = napi_default,
			.data = NULL
		}
	};
	status = napi_define_properties(env, exports, 2, desc);

	if (status != napi_ok)
		return NULL;
	return exports;

}

NAPI_MODULE(bye, init)
