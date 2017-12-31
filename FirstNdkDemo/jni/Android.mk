LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := my_first_ndk
LOCAL_SRC_FILES := my_first_ndk.c

include $(BUILD_SHARED_LIBRARY)
