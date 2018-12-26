#include "test.h"
#include "com_mub_app_HelloJNI.h"
#include <cstdio>

test::test()
{
}


test::~test()
{
}

extern "C" {
	JNIEXPORT void JNICALL Java_com_mub_app_HelloJNI_sayHello(JNIEnv *env, jobject, jstring name)
	{          
		const char *str = env->GetStringUTFChars(name, 0);
		printf("Hello %s !", str);
		//need to release this string when done with it in order to
		//avoid memory leak
		(*env).ReleaseStringUTFChars(name, str);

	}


	JNIEXPORT jint JNICALL Java_com_mub_app_HelloJNI_incrementNumber
		(JNIEnv *, jobject, jint val)
	{
		return ++val;
	}
}