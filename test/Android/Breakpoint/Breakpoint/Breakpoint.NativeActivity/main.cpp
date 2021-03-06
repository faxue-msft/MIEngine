/*
* Copyright (C) 2010 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "AndroidProject1.NativeActivity", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "AndroidProject1.NativeActivity", __VA_ARGS__))

void break_test_1()
{
    for (int i = 0; i < 2; i++)
    {
        int j = 0; // set bp here, line 25
        j++;
    }

    int i = 0; i++; //set bp here, line 29
}

void loop_while_true()
{
    bool flag = true;

    while (flag)
    {
        int i = 0; // set bp here, line 38
    }
}

void break_test_2()
{
    loop_while_true();
    int i = 0; // set bp here, line 45

    loop_while_true();
    int j = 0; // set bp here, line 48
}

/**
* This is the main entry point of a native application that is using
* android_native_app_glue.  It runs in its own thread, with its own
* event loop for receiving input events and doing other things.
*/
void android_main(struct android_app* state) {

    break_test_1();
    break_test_2();
}
