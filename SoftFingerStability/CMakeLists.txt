set(target CnoidSoftFingerStabilityPlugin)

set(sources
  SoftFingerStabilityPlugin.cpp
  SoftFingerStabilityBar.cpp
  SoftFingerStabilityHandler.cpp
  )

set(headers
  SoftFingerStabilityBar.h
  SoftFingerStabilityHandler.h
  )

if(CNOID_VERSION EQUAL 1.0 OR CNOID_VERSION EQUAL 1.1)
  add_library(${target} SHARED ${sources} ${headers})
else()
  add_cnoid_plugin(${target} SHARED ${sources} ${headers})
endif()

set_target_properties(${target} PROPERTIES VERSION 0.0.0 SOVERSION 0)
#set_target_properties(${target} PROPERTIES DEFINE_SYMBOL "EXCADE_SAMPLE1_MAKE_DLL")

if(MSVC)
  add_definitions(-DEXCADE_SOFTFINGERSTABILITY_MAKE_DLL)
endif()

target_link_libraries(${target} CnoidBodyPlugin CnoidGraspPlugin CnoidGeometryHandlerPlugin)

apply_common_setting_for_plugin(${target})

#add_subdirectory(project)
