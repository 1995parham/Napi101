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

	sleep(100);
	printf("Hello sync");

	napi_create_number(env, 1373, &retval);

	return retval;
}

void bye_async_execute(napi_env env, void *data)
{
	sleep(100);
	printf("Hello async");
}

void bye_async_complete(napi_env env, napi_status status, void* data)
{
	printf("Hello completed async");
}

napi_value bye_async(napi_env env, napi_callback_info info)
{
	napi_value retval;
	napi_async_work work;

	napi_create_async_work(env, bye_async_execute, bye_async_complete, NULL, &work);
	napi_queue_async_work(env, work);

	napi_create_number(env, 1373, &retval);

	return retval;
}



void init(napi_env env, napi_value exports, napi_value module, void* priv)
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
		return;

}

NAPI_MODULE(bye, init)
