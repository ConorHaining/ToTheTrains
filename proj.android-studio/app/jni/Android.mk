LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := $(LOCAL_PATH)/hellocpp/main.cpp \
                   $(LOCAL_PATH)/../../../Classes/AppDelegate.cpp \
                   $(LOCAL_PATH)/../../../Classes/StationScene.cpp \
                   $(LOCAL_PATH)/../../../Classes/TitleScene.cpp \
                   $(LOCAL_PATH)/../../../Classes/Menu.cpp \
                   $(LOCAL_PATH)/../../../Classes/EntityInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/EntityManager.cpp \
                   $(LOCAL_PATH)/../../../Classes/ComponentInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/SpawnLocation.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/DespawnLocation.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/TrainType.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/StoppingLocation.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/ArrivalSequence.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/DepartureSequence.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/ArrivalTime.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/DepartureTime.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/Satisfaction.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/Time.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/SpriteComponent.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/LabelComponent.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/WarningPosition.cpp \
                   $(LOCAL_PATH)/../../../Classes/Components/ScoreComponent.cpp \
                   $(LOCAL_PATH)/../../../Classes/Entities/Station.cpp \
                   $(LOCAL_PATH)/../../../Classes/Entities/Train.cpp \
                   $(LOCAL_PATH)/../../../Classes/Entities/GameClock.cpp \
                   $(LOCAL_PATH)/../../../Classes/Entities/WarningSymbol.cpp \
                   $(LOCAL_PATH)/../../../Classes/Entities/ScoreEntity.cpp \
                   $(LOCAL_PATH)/../../../Classes/Entities/GameStory.cpp \
                   $(LOCAL_PATH)/../../../Classes/Systems/StationRenderSystem.cpp \
                   $(LOCAL_PATH)/../../../Classes/Systems/TrainManagementSystem.cpp \
                   $(LOCAL_PATH)/../../../Classes/Systems/GameTimeSystem.cpp \
                   $(LOCAL_PATH)/../../../Classes/Systems/ScoreSystem.cpp \
                   $(LOCAL_PATH)/../../../Classes/Systems/LevelCreationSystem.cpp \
                   $(LOCAL_PATH)/../../../Classes/Systems/GameStorySystem.cpp \
                   $(LOCAL_PATH)/../../../Classes/include/*



LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
