# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_arm_mark1_controller_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED arm_mark1_controller_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(arm_mark1_controller_FOUND FALSE)
  elseif(NOT arm_mark1_controller_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(arm_mark1_controller_FOUND FALSE)
  endif()
  return()
endif()
set(_arm_mark1_controller_CONFIG_INCLUDED TRUE)

# output package information
if(NOT arm_mark1_controller_FIND_QUIETLY)
  message(STATUS "Found arm_mark1_controller: 0.0.0 (${arm_mark1_controller_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'arm_mark1_controller' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${arm_mark1_controller_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(arm_mark1_controller_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${arm_mark1_controller_DIR}/${_extra}")
endforeach()
