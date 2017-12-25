LOCAL_PATH := $(call my-dir)

################################################################################
include $(CLEAR_VARS)
LOCAL_MODULE := libamr

LOCAL_SRC_FILES := $(notdir $(wildcard $(LOCAL_PATH)/*.c))
LOCAL_ARM_MODE := arm
LOCAL_C_INCLUDES := $(LOCAL_PATH)/


include $(BUILD_STATIC_LIBRARY)

#################################################################################
include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES += libutils libmedia libz libbinder libdl libcutils libc liblog
LOCAL_MODULE    := libamr
LOCAL_SRC_FILES := $(notdir $(wildcard $(LOCAL_PATH)/*.c))
LOCAL_ARM_MODE := arm
LOCAL_MODULE_TAGS := optional
LOCAL_C_INCLUDES := $(LOCAL_PATH)/

ifeq ($(shell test $(PLATFORM_SDK_VERSION) -ge 26 && echo OK),OK)
LOCAL_PROPRIETARY_MODULE := true
endif

LOCAL_PRELINK_MODULE := false

include $(BUILD_SHARED_LIBRARY)